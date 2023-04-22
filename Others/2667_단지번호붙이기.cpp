#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
string board[26];
bool isVis[26][26];
vector<int> v;

void BFS()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!isVis[i][j] && board[i][j] == '1')
			{
				int size = 0;
				queue<pair<int, int>> q;

				isVis[i][j] = true;
				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					size++;

					for (int dir = 0; dir < 4; ++dir)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];

						if (curX < 0 || curY < 0 || curX >= N || curY >= N)
						{
							continue;
						}

						if (isVis[curX][curY] || board[curX][curY] == '0')
						{
							continue;
						}

						isVis[curX][curY] = true;
						q.push({ curX, curY });
					}
				}
				v.push_back(size);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
	}
	BFS();
	sort(v.begin(), v.end());

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << '\n';
	}

	return 0;
}