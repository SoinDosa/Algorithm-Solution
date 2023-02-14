// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/40081492d92a4e1d9c805d23bf485942
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int monkeyDX[4] = { 1, 0, -1, 0 };
int monkeyDY[4] = { 0, 1, 0, -1 };
int horseDX[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
int horseDY[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int board[201][201];
int dist[31][201][201];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K = 0;
	int W = 0;
	int H = 0;
	int minDist = 0x7FFFFFFF;
	queue<tuple<int, int, int>> q;

	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			cin >> board[i][j];
		}
	}

	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;
	while (!q.empty())
	{
		int curK = 0;
		int curH = 0;
		int curW = 0;

		tie(curK, curH, curW) = q.front();
		q.pop();
		if (curK < K)
		{
			for (int i = 0; i < 8; ++i)
			{
				int curX = curH + horseDX[i];
				int curY = curW + horseDY[i];

				if (curX < 0 || curX >= H || curY < 0 || curY >= W)
				{
					continue;
				}

				if (board[curX][curY] != 0)
				{
					continue;
				}

				if (dist[curK + 1][curX][curY] != 0)
				{
					continue;
				}

				dist[curK + 1][curX][curY] = dist[curK][curH][curW] + 1;
				q.push({ curK + 1, curX, curY });
			}
		}
		// 현재 말처럼 움직인 횟수가 K보다 적을 경우 말처럼 움직이고 -> 횟수를 증가시킨 다음 -> 큐에 넣음

		for (int i = 0; i < 4; ++i)
		{
			int curX = curH + monkeyDX[i];
			int curY = curW + monkeyDY[i];

			if (curX < 0 || curX >= H || curY < 0 || curY >= W)
			{
				continue;
			}

			if (board[curX][curY] != 0)
			{
				continue;
			}

			if (dist[curK][curX][curY] != 0)
			{
				continue;
			}

			dist[curK][curX][curY] = dist[curK][curH][curW] + 1;
			q.push({ curK, curX, curY });
		}
		// 말처럼 움직이지 않는 경우는 K를 유지한채로 큐에 넣음
	}

	for (int i = 0; i <= K; ++i)
	{
		if (dist[i][H - 1][W - 1] != 0)
		{
			minDist = min(minDist, dist[i][H - 1][W - 1]);
		}
	}

	if (minDist == 0x7FFFFFFF)
	{
		cout << -1;
	}
	else
	{
		cout << minDist - 1;
	}
}