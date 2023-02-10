#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
int M;
int sea[301][301];
int nearSea[301][301];
bool vis[301][301];

bool IsInBoundary(int x, int y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

bool IsDoubleGlacier()
{
	queue<pair<int, int>> q;
	int glacierCount = 0;

	for (int i = 0; i < N; ++i)
	{
		fill(vis[i], vis[i] + M, false);
	}
	// �湮��� �ʱ�ȭ

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (sea[i][j] > 0 && vis[i][j] == false)
			{
				glacierCount++;
				if (glacierCount >= 2)
				{
					return true;
				}

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

						if (IsInBoundary(curX, curY))
						{
							continue;
						}

						if (sea[curX][curY] <= 0 || vis[curX][curY] == true)
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

	return false;
}

void CheckNearSea(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		int curX = x + dx[i];
		int curY = y + dy[i];

		if (IsInBoundary(curX, curY))
		{
			continue;
		}

		if (sea[curX][curY] <= 0)
		{
			nearSea[x][y]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool isEnd = false;
	int totalYear = 0;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> sea[i][j];
		}
	}

	while (isEnd == false)
	{
		if (IsDoubleGlacier())
		{
			isEnd = true;
			break;
		}
		// 1���� ���� ������ �� ��� �̻����� �и��Ǵ� ���� üũ

		int seaCount = 0;

		for (int i = 0; i < N; ++i)
		{
			fill(nearSea[i], nearSea[i] + M, 0);
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (sea[i][j] <= 0)
				{
					seaCount++;
				}
				else
				{
					CheckNearSea(i, j);
				}
			}
		}

		if (seaCount == N * M)
		{
			totalYear = 0;
			isEnd = true;
			break;
		}
		// �ε��̰� �Ǳ� ���� ��� ��ƹ��ȴٸ� �� ����� 0���� �ٲٰ� break

		totalYear++;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (sea[i][j] > 0)
				{
					sea[i][j] -= nearSea[i][j];
				}
			}
		}
		// 1���� ���������� ���ϸ��� ������ �ٴ��� ���� üũ�ϰ� ���ҽ�Ŵ
	}

	cout << totalYear;

	return 0;
}