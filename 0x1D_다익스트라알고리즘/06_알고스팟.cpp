#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const int INF = 0x3F333333;
char board[101][101];
int costs[101][101];
int N, M;

bool oob(const int& x, const int& y)
{
	return (x < 1 || x > N || y < 1 || y > M);
}

int main()
{
	cin >> M >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			fill(costs[i], costs[i] + 1 + M, INF);
			cin >> board[i][j];
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	costs[1][1] = 0;
	pq.push({ costs[1][1], 1, 1 });
	while (!pq.empty())
	{
		int curCost, curX, curY;
		tie(curCost, curX, curY) = pq.top();
		pq.pop();

		if (curCost != costs[curX][curY])
		{
			continue;
		}

		for (int dir = 0; dir < 4; ++dir)
		{
			int nxtX = curX + dx[dir];
			int nxtY = curY + dy[dir];

			if (oob(nxtX, nxtY))
			{
				continue;
			}

			if (costs[nxtX][nxtY] <= curCost + (board[nxtX][nxtY] - '0'))
			{
				continue;
			}
			costs[nxtX][nxtY] = curCost + (board[nxtX][nxtY] - '0');
			pq.push({ costs[nxtX][nxtY], nxtX, nxtY });
		}
	}
	cout << costs[N][M];
}
