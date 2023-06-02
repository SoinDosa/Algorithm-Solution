#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
string board[26];
bool isVis[26][26];
int N;
vector<int> results;

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= N);
}

void bfs()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == '0')
			{
				continue;
			}

			if (isVis[i][j])
			{
				continue;
			}

			queue<pair<int, int>> q;
			int cnt = 0;
			
			q.push({ i, j });
			isVis[i][j] = true;
			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();
				cnt++;

				for (int dir = 0; dir < 4; ++dir)
				{
					int curX = cur.first + dx[dir];
					int curY = cur.second + dy[dir];

					if (oob(curX, curY))
					{
						continue;
					}

					if (isVis[curX][curY] || board[curX][curY] == '0')
					{
						continue;
					}

					q.push({ curX, curY });
					isVis[curX][curY] = true;
				}
			}

			results.push_back(cnt);
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

	bfs();
	sort(results.begin(), results.end());

	cout << results.size() << '\n';
	for (int e : results)
	{
		cout << e << '\n';
	}

	return 0;
}