#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int farm[51][51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;
	int M = 0;
	int N = 0;
	int K = 0;

	cin >> T;
	while (T--)
	{
		queue<pair<int, int>> q;
		int warm = 0;

		cin >> M >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			fill(farm[i], farm[i] + M, 0);
		}

		while (K--)
		{
			int x = 0;
			int y = 0;

			cin >> x >> y;
			farm[y][x] = 1;
			// X, Y 위치 유의
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (farm[i][j] == 1)
				{
					q.push({ i, j });
					warm++;

					while (!q.empty())
					{
						pair<int, int> cur = q.front();
						
						q.pop();
						for (int k = 0; k < 4; ++k)
						{
							int curX = cur.first + dx[k];
							int curY = cur.second + dy[k];

							if (curX < 0 || curX >= N || curY < 0 || curY >= M)
							{
								continue;
							}

							if (farm[curX][curY] != 1)
							{
								continue;
							}

							farm[curX][curY] = 0;
							// 굳이 visit을 체크하지 않고 farm을 0으로 만듬으로써 메모리 공간 최소화
							q.push({ curX, curY });
						}
					}
				}
			}
		}

		cout << warm << '\n';
	}

	return 0;
}