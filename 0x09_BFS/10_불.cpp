#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string building[1001];
int fire[1001][1001];
int sanggeun[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int w = 0;
		int h = 0;
		int fastestTime = 0;
		queue<pair<int, int>> sanggeunQ;
		queue<pair<int, int>> fireQ;

		cin >> w >> h;
		for (int i = 0; i < h; ++i)
		{
			fill(fire[i], fire[i] + w, -1);
			fill(sanggeun[i], sanggeun[i] + w, -1);
		}
		for (int i = 0; i < h; ++i)
		{
			cin >> building[i];
			for (int j = 0; j < w; ++j)
			{
				if (building[i][j] == '*')
				{
					fire[i][j] = 0;
					fireQ.push({ i, j });
				}
				else if (building[i][j] == '@')
				{
					sanggeun[i][j] = 0;
					sanggeunQ.push({ i,j });
				}
			}
		}

		while (!fireQ.empty())
		{
			pair<int, int> cur = fireQ.front();

			fireQ.pop();
			for (int i = 0; i < 4; ++i)
			{
				int curX = cur.first + dx[i];
				int curY = cur.second + dy[i];

				if (curX < 0 || curX >= h || curY < 0 || curY >= w)
				{
					continue;
				}

				if (building[curX][curY] == '#' || fire[curX][curY] != -1)
				{
					continue;
				}

				fire[curX][curY] = fire[cur.first][cur.second] + 1;
				fireQ.push({ curX, curY });
			}
		}

		while (!sanggeunQ.empty() && fastestTime == 0)
		{
			pair<int, int> cur = sanggeunQ.front();

			sanggeunQ.pop();
			for (int i = 0; i < 4; ++i)
			{
				int curX = cur.first + dx[i];
				int curY = cur.second + dy[i];

				if (curX < 0 || curX >= h || curY < 0 || curY >= w)
				{
					fastestTime = sanggeun[cur.first][cur.second] + 1;
					break;
				}

				if (building[curX][curY] == '#' || sanggeun[curX][curY] != -1)
				{
					continue;
				}

				if (fire[curX][curY] != -1 && fire[curX][curY] <= sanggeun[cur.first][cur.second] + 1)
				{
					continue;
				}

				sanggeun[curX][curY] = sanggeun[cur.first][cur.second] + 1;
				sanggeunQ.push({ curX, curY });
			}
		}

		if (fastestTime != 0)
		{
			cout << fastestTime << '\n';
		}
		else
		{
			cout << "IMPOSSIBLE\n";
		}
	}

	return 0;
}