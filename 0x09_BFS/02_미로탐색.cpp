#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[101][101];
int dis[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;
	queue<pair<int, int>> q;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		string input;

		cin >> input;
		for (int j = 1; j <= M; ++j)
		{
			board[i][j] = input[j - 1] - '0';
		}
	}

	q.push({ 1,1 });
	dis[1][1] = 1;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int curX = cur.first + dx[i];
			int curY = cur.second + dy[i];

			if (curX < 1 || curX > N || curY < 1 || curY > M)
			{
				continue;
			}

			if (board[curX][curY] != 1 || dis[curX][curY] != 0)
			{
				continue;
			}

			q.push({ curX, curY });
			dis[curX][curY] = dis[cur.first][cur.second] + 1;
		}
	}

	cout << dis[N][M];

	return 0;
}