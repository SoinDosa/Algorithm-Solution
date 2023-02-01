#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string paint[101];
bool vis[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int normal = 0;
	int weak = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> paint[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vis[i][j] != true)
			{
				queue<pair<int, int>> q;
				char color = paint[i][j];

				normal++;
				vis[i][j] = true;
				q.push({ i, j });

				if (paint[i][j] == 'G')
				{
					paint[i][j] = 'R';
				}

				while (!q.empty())
				{
					pair<int, int> cur = q.front();

					q.pop(); 
					for (int k = 0; k < 4; ++k)
					{
						int curX = cur.first + dx[k];
						int curY = cur.second + dy[k];

						if (curX < 0 || curX >= N || curY < 0 || curY >= N)
						{
							continue;
						}

						if (paint[curX][curY] != color || vis[curX][curY] == true)
						{
							continue;
						}

						vis[curX][curY] = true;
						q.push({ curX, curY });

						if (paint[curX][curY] == 'G')
						{
							paint[curX][curY] = 'R';
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		fill(vis[i], vis[i] + N, false);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vis[i][j] != true)
			{
				queue<pair<int, int>> q;
				char color = paint[i][j];

				weak++;
				vis[i][j] = true;
				q.push({ i, j });

				while (!q.empty())
				{
					pair<int, int> cur = q.front();

					q.pop();
					for (int k = 0; k < 4; ++k)
					{
						int curX = cur.first + dx[k];
						int curY = cur.second + dy[k];

						if (curX < 0 || curX >= N || curY < 0 || curY >= N)
						{
							continue;
						}

						if (paint[curX][curY] != color || vis[curX][curY] == true)
						{
							continue;
						}

						vis[curX][curY] = true;
						q.push({ curX, curY });
					}
				}
			}
		}
	}

	cout << normal << ' ' << weak;

	return 0;
}
