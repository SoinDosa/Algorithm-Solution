#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int SIZE = 5;
const int INF = 0x7FFFFFFF;
const int dx[6] = { 1, -1, 0, 0, 0, 0 };
const int dy[6] = { 0, 0, 1, -1, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, 1, -1 };

int board[4][5][5][5];
// [dir][x][y][z]
int copiedBoard[5][5][5];
int minResult = INF;

bool oob(const int& x, const int& y, const int& z)
{
	return (x < 0 || x >= SIZE || y < 0 || y >= SIZE || z < 0 || z >= SIZE);
}

int bfs()
{
	int dist[5][5][5] = {};
	queue<tuple<int, int, int>> q;

	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		int curX, curY, curZ;
		tie(curX, curY, curZ) = q.front();
		q.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nxtX = curX + dx[dir];
			int nxtY = curY + dy[dir];
			int nxtZ = curZ + dz[dir];

			if (oob(nxtX, nxtY, nxtZ))
			{
				continue;
			}

			if (dist[nxtX][nxtY][nxtZ] != 0 || copiedBoard[nxtX][nxtY][nxtZ] == 0)
			{
				continue;
			}

			if (nxtX == SIZE - 1 && nxtY == SIZE - 1 && nxtZ == SIZE - 1)
			{
				return dist[curX][curY][curZ];
			}

			dist[nxtX][nxtY][nxtZ] = dist[curX][curY][curZ] + 1;
			q.push({ nxtX, nxtY, nxtZ });
		}
	}

	return INF;
}

void brute_force(const int layers[5])
{
	int maxFlag = 1 << 2 * 5;
	// 모든 방향 경우의 수는 4 ^ 5

	for (int brute = 0; brute < maxFlag; ++brute)
	{
		int temp = brute;

		for (int i = 0; i < 5; ++i)
		{
			int dir = temp % 4;
			for (int y = 0; y < SIZE; ++y)
			{
				for (int z = 0; z < SIZE; ++z)
				{
					copiedBoard[i][y][z] = board[dir][layers[i]][y][z];
				}
			}
			// 방향, 쌓는 순서에 맞게 미로를 복사한다

			if (temp != 0)
			{
				temp /= 4;
			}
		}

		if (copiedBoard[0][0][0] == 0 || copiedBoard[SIZE - 1][SIZE - 1][SIZE - 1] == 0)
		{
			continue;
		}
		// 탈출이 불가능한 경우일 경우 생략

		minResult = min(minResult, bfs());
		// BFS 수행해서 가장 적은 이동횟수 반영
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int x = 0; x < SIZE; ++x)
	{
		for (int y = 0; y < SIZE; ++y)
		{
			for (int z = 0; z < SIZE; ++z)
			{
				cin >> board[0][x][y][z];
			}
		}
	}
	// 원본 입력

	for (int x = 0; x < SIZE; ++x)
	{
		for (int y = 0; y < SIZE; ++y)
		{
			for (int z = 0; z < SIZE; ++z)
			{
				board[1][x][y][z] = board[0][x][SIZE - z - 1][y];
				board[2][x][y][z] = board[0][x][SIZE - y - 1][SIZE - z - 1];
				board[3][x][y][z] = board[0][x][z][SIZE - y - 1];
				// 90, 180, 270도 회전
			}
		}
	}

	int layers[5] = { 0, 1, 2, 3, 4 };
	do
	{
		brute_force(layers);
	} while (next_permutation(layers, layers + SIZE));
	// 층을 쌓을 수 있는 모든 경우의 수 탐색

	if (minResult == INF)
	{
		minResult = -1;
	}
	cout << minResult;

	return 0;
}