#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char board[1000][1000];
int dis[1000][1000][2];
// dis[x][y][0] : ���� �ϳ��� �μ��� �ʰ� x,y���� ���°� �ɸ��� ���
// dis[x][y][1] : ���� �ϳ��� �μ��� x,y���� ���°� �ɸ��� ���

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
		// tie�� ����� tuple ����
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
			// curX, curY �� �μ����ʴ� ���
			
			if (!isBreak && board[curX][curY] == '1' && dis[curX][curY][1] == 0)
			{
				dis[curX][curY][1] = dis[x][y][isBreak] + 1;
				q.push({ curX, curY, 1 });
			}
			// curX, curY �� �μ��� ���
			// !isBreak ���� ������ �� �� �μ����� �ִ� ��� �ٽ� �μ��� ����
		}
	}

	if (!isEscape)
	{
		cout << -1;
	}
}