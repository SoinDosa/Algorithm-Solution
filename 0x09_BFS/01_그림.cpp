#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[501][501];
bool isVisit[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int m = 0;
	int total = 0;
	int maxSize = 0;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 1 && isVisit[i][j] != true)
			{
				queue<pair<int, int>> q;
				int size = 0;

				isVisit[i][j] = true;
				total++;

				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> cur = q.front();

					q.pop();
					size++;

					for (int k = 0; k < 4; k++)
					{
						int curX = cur.first + dx[k];
						int curY = cur.second + dy[k];

						if (curX < 0 || curX >= n || curY < 0 || curY >= m)
						{
							continue;
						}

						if (board[curX][curY] != 1 || isVisit[curX][curY] == true)
						{
							continue;
						}

						isVisit[curX][curY] = true;
						q.push({ curX, curY });
					}
				}

				if (size > maxSize)
				{
					maxSize = size;
				}
				// 반복문에서 삼항연산자를 사용하는 경우?
				// 반복할 때 마다 "무조건" 대입연산을 실행하는 코스트 생각
			}
		}
	}

	cout << total << '\n' << maxSize;

	return 0;
}