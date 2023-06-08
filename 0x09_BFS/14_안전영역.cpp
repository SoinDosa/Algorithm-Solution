#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> board;
int N;

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int bfs(const int& height)
{
	int safeAreaCnt = 0;
	vector<vector<bool>> isVis(N, vector<bool>(N, false));
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!isVis[i][j] && board[i][j] > height)
			{
				queue<pair<int, int>> q;

				++safeAreaCnt;
				q.push({ i, j });
				isVis[i][j] = true;

				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nxtX = cur.first + dx[dir];
						int nxtY = cur.second + dy[dir];

						if (oob(nxtX, nxtY))
						{
							continue;
						}

						if (isVis[nxtX][nxtY] || board[nxtX][nxtY] <= height)
						{
							continue;
						}

						q.push({ nxtX, nxtY });
						isVis[nxtX][nxtY] = true;
					}
				}
			}
		}
	}

	return safeAreaCnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	int maxHeight = 0;
	for (int i = 0; i < N; ++i)
	{
		vector<int> row(N);

		for (int j = 0; j < N; ++j)
		{
			cin >> row[j];
			maxHeight = max(maxHeight, row[j]);
		}
		board.push_back(row);
	}

	int maxSafeArea = 1;
	// 아무 지역도 물에 안잠길 수 있으므로 1부터 시작해야함
	for (int brute = 0; brute <= maxHeight; ++brute)
	{
		maxSafeArea = max(maxSafeArea, bfs(brute));
	}

	cout << maxSafeArea;

	return 0;
}