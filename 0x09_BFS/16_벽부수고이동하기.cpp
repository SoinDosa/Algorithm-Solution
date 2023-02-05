#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[1000][1000];
int dis[1000][1000][2];
// dis[x][y][0] : 벽을 하나도 부수지 않고 x,y까지 가는게 걸리는 비용
// dis[x][y][1] : 벽을 하나만 부수고 x,y까지 가는게 걸리는 비용

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;
	bool isEscape = false;
	queue<tuple<int, int, int>> q;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	dis[0][0][0] = dis[0][0][1] = 1;
	q.push({ 0, 0, 0 });
	while (!q.empty() && !isEscape)
	{
		int x = 0;
		int y = 0;
		int isBreak = 0;

		tie(x, y, isBreak) = q.front();
		// tie를 사용한 tuple 사용법
		if (x == N - 1 && y == M - 1)
		{
			isEscape = true;
			cout << dis[x][y][isBreak];
			break;
		}

		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int curX = x + dx[i];
			int curY = y + dy[i];

			if (curX < 0 || curX >= N || curY < 0 || curY >= M)
			{
				continue;
			}

			if (board[curX][curY] == '0' && dis[curX][curY][isBreak] == 0)
			{
				dis[curX][curY][isBreak] = dis[x][y][isBreak] + 1;
				q.push({ curX, curY, isBreak });
			}
			// curX, curY 를 부수지않는 경우
			
			if (!isBreak && board[curX][curY] == '1' && dis[curX][curY][1] == 0)
			{
				dis[curX][curY][1] = dis[x][y][isBreak] + 1;
				q.push({ curX, curY, 1 });
			}
			// curX, curY 를 부수는 경우
			// !isBreak 조건 때문에 한 번 부순적이 있는 경우 다시 부수지 않음
		}
	}

	if (!isEscape)
	{
		cout << -1;
	}
}