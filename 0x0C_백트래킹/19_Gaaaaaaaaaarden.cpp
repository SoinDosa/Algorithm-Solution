// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// Commented by : Soindosa
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;
int N, M, G, R;
int board[51][51];
vector<pair<int, int>> pos;
int posSize;
int brute[10];

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int solve()
{
	int flowerCnt = 0;
	pair<int, int> state[51][51];
	// {arrival time, color};
	queue<pair<int, int>> q;

	for (int i = 0; i < posSize; ++i)
	{
		if (brute[i] == GREEN || brute[i] == RED)
		{
			state[pos[i].first][pos[i].second] = { 0, brute[i] };
			q.push(pos[i]);
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		int curTime = state[cur.first][cur.second].first;
		int curColor = state[cur.first][cur.second].second;

		if (curColor == FLOWER)
		{
			continue;
		}
		// 꽃이면 생략

		for (int dir = 0; dir < 4; ++dir)
		{
			int nxtX = cur.first + dx[dir];
			int nxtY = cur.second + dy[dir];

			if (oob(nxtX, nxtY))
			{
				continue;
			}

			if (board[nxtX][nxtY] == 0)
			{
				continue;
			}
			// 호수면 이동 불가

			if (state[nxtX][nxtY].second == EMPTY)
			{
				state[nxtX][nxtY] = { curTime + 1, curColor };
				q.push({ nxtX, nxtY });
			}
			// 비어있다면 일반적인 BFS
			else if (state[nxtX][nxtY].second == RED)
			{
				if (curColor == GREEN && state[nxtX][nxtY].first == curTime + 1)
				{
					flowerCnt++;
					state[nxtX][nxtY].second = FLOWER;
				}
			}
			else if (state[nxtX][nxtY].second == GREEN)
			{
				if (curColor == RED && state[nxtX][nxtY].first == curTime + 1)
				{
					flowerCnt++;
					state[nxtX][nxtY].second = FLOWER;
				}
			}
		}
	}
	return flowerCnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				pos.push_back({ i, j });
			}
		}
	}
	posSize = pos.size();

	fill(brute + posSize - G - R, brute + posSize - R, GREEN);
	fill(brute + posSize - R, brute + posSize, RED);
	// brute를 이용해 GREEN은 1, RED는 2, 배양액을 뿌리지 않으면 0으로 설정
	int maxFlower = 0;
	do
	{
		maxFlower = max(maxFlower, solve());
	} while (next_permutation(brute, brute + posSize));

	cout << maxFlower;

	return 0;
}