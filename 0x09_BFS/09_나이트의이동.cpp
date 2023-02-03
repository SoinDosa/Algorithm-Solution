#include <iostream>
#include <queue>

using namespace std;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dist[301][301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;
	int I = 0;

	cin >> T;
	while (T--)
	{
		int startX = 0;
		int startY = 0;
		int destX = 0;
		int destY = 0;
		int result = 0;
		queue<pair<int, int>> q;

		cin >> I;
		cin >> startX >> startY;
		cin >> destX >> destY;

		if (startX == destX && startY == destY)
		{
			result = 0;
		}
		else
		{
			for (int i = 0; i < I; ++i)
			{
				fill(dist[i], dist[i] + I, -1);
			}
			dist[startX][startY] = 0;
			q.push({ startX, startY });
		}

		while (!q.empty())
		{
			pair<int, int> cur = q.front();

			q.pop();
			for (int i = 0; i < 8; ++i)
			{
				int curX = cur.first + dx[i];
				int curY = cur.second + dy[i];

				if (curX < 0 || curX >= I || curY < 0 || curY >= I)
				{
					continue;
				}

				if (curX == destX && curY == destY)
				{
					result = dist[cur.first][cur.second] + 1;
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}

				if (dist[curX][curY] != -1)
				{
					continue;
				}

				dist[curX][curY] = dist[cur.first][cur.second] + 1;
				q.push({ curX, curY });
			}
		}

		cout << result << '\n';
	}

	return 0;
}