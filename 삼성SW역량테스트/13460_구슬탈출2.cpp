// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/c6dff411258544ce8393f745f463df33
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M;
pair<int, int> red, blue;
// 빨간 구슬과 파란 구슬의 위치
string board[11];
int dist[11][11][11][11];
// dist[a][b][c][d] 빨간 구슬이 a, b이고 파란 구슬이 c,d에 위치한 상황에 도달하기 위한 동작의 횟수

int bfs()
{
	queue<tuple<int, int, int, int>> q;
	q.push({ red.first, red.second, blue.first, blue.second });
	dist[red.first][red.second][blue.first][blue.second] = 0;
	// 최초 작업

	while (!q.empty())
	{
		int rx = 0, ry = 0, bx = 0, by = 0;
		tie(rx, ry, bx, by) = q.front();
		q.pop();

		int cnt = dist[rx][ry][bx][by];

		if (cnt >= 10)
		{
			return -1;
		}
		// 10번 넘게 방향을 돌려도 탈출 못하면 -1;

		for (int dir = 0; dir < 4; ++dir)
		{
			int curRX = rx;
			int curRY = ry;
			int curBX = bx;
			int curBY = by;

			while (board[curBX + dx[dir]][curBY + dy[dir]] == '.')
			{
				curBX += dx[dir];
				curBY += dy[dir];
			}
			// 파란 공 이동, 이동할 칸이 '.'이라면 계속 방향만큼 이동시킨다
			if (board[curBX + dx[dir]][curBY + dy[dir]] == 'O')
			{
				continue;
			}
			// 파란 공이 탈출했다면 실패, continue

			while (board[curRX + dx[dir]][curRY + dy[dir]] == '.')
			{
				curRX += dx[dir];
				curRY += dy[dir];
			}
			// 빨간 공 이동
			if (board[curRX + dx[dir]][curRY + dy[dir]] == 'O')
			{
				return cnt + 1;
			}
			// 빨간 공이 탈출했다면 종료, 바로 정답 반환

			if (curRX == curBX && curRY == curBY)
			{
				switch (dir)
				{
				case 0:
					ry < by ? curRY-- : curBY--;
					break;
					// 더 작은게 늦게 출발한 쪽이므로 해당 값을 --
				case 1:
					rx < bx ? curRX-- : curBX--;
					break;
				case 2:
					ry > by ? curRY++ : curBY++;
					break;
				case 3:
					rx > bx ? curRX++ : curBX++;
					break;
				}
			}
			// 빨간공과 파란공이 겹친 경우 늦게 출발한 구슬을 한칸 뒤로 이동

			if (dist[curRX][curRY][curBX][curBY] != -1)
			{
				continue;
			}
			// 이미 해당 경우를 계산한 적이 있다면 continue;
			dist[curRX][curRY][curBX][curBY] = cnt + 1;
			q.push({ curRX, curRY, curBX, curBY });
		}
	}
	
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				fill(dist[i][j][k], dist[i][j][k] + 10, -1);
			}
		}
	}
	// 거리 배열 초기화

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 'B')
			{
				blue = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R')
			{
				red = { i, j };
				board[i][j] = '.';
			}
		}
		// 빨간공, 파란공의 위치를 저장한 후 해당 위치를 .으로 바꿈
	}

	cout << bfs();

	return 0;
}