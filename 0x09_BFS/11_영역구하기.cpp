#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int board[101][101];
bool isVis[101][101];
int M, N, K;
int cnt;
vector<int> emptySizes;

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

void fill_board(const int& x1, const int& y1, const int& x2, const int& y2)
{
	for (int i = x1; i < x2; ++i)
	{
		for (int j = y1; j < y2; ++j)
		{
			board[i][j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> K;
	while (K--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		fill_board(x1, y1, x2, y2);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!isVis[i][j] && board[i][j] == 0)
			{
				queue<pair<int, int>> q;
				int emptySize = 0;

				cnt++;
				isVis[i][j] = true;
				q.push({ i, j });

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					emptySize++;

					for (int dir = 0; dir < 4; ++dir)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];

						if (oob(curX, curY))
						{
							continue;
						}

						if (isVis[curX][curY] || board[curX][curY] == 1)
						{
							continue;
						}

						isVis[curX][curY] = true;
						q.push({ curX, curY });
					}
				}
				emptySizes.push_back(emptySize);
			}
		}
	}

	sort(emptySizes.begin(), emptySizes.end());

	cout << cnt << '\n';
	for (int e : emptySizes)
	{
		cout << e << ' ';
	}

	return 0;
}