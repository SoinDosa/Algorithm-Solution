// Authored by : yongjunleeme
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/1b1d9408543c440885788af2cfade28c
#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[101][101];
bool vis[101][101];
int dist[101][101];
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int islandCount = 0;
	int minimumDist = INT_MAX;
	// INT_MAX�� climits����� �����ؾ� ��밡��
	queue<pair<int, int>> q;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] != 0 && vis[i][j] != true)
			{
				islandCount++;
				vis[i][j] = true;
				board[i][j] = islandCount;
				// �� ���� ��ȣ�� �Űܼ� board�� ������, �̷� �����!
				q.push({ i, j });
				while (!q.empty())
				{
					pair<int, int> cur = q.front();

					q.pop();
					for (int dir = 0; dir < 4; ++dir)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];

						if (curX < 0 || curX >= N || curY < 0 || curY >= N)
						{
							continue;
						}

						if (board[curX][curY] == 0 || vis[curX][curY] == true)
						{
							continue;
						}

						vis[curX][curY] = true;
						board[curX][curY] = islandCount;
						q.push({ curX, curY });
					}
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		fill(dist[i], dist[i] + N, -1);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] != 0)
			{
				bool escape = false;

				q.push({ i, j });
				dist[i][j] = 0;
				while (!q.empty() && escape == false)
				{
					pair<int, int> cur = q.front();

					q.pop();
					for (int dir = 0; dir < 4; ++dir)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];

						if (curX < 0 || curX >= N || curY < 0 || curY >= N)
						{
							continue;
						}

						if (dist[curX][curY] >= 0 || board[i][j] == board[curX][curY])
						{
							continue;
						}
						// �̹� �Ÿ��� ������ ���̰ų� ���� ���̶�� ��ŵ

						if (board[curX][curY] != 0 && board[i][j] != board[curX][curY])
						{
							minimumDist = min(minimumDist, dist[cur.first][cur.second]);
							while (!q.empty())
							{
								q.pop();
							}
							escape = true;
							break;
						}
						// �ٸ� ���� ������ ���� �ϳ��� �ִٸ� �ּ� �Ÿ��� �����ϰ� while�� �ߴ�

						dist[curX][curY] = dist[cur.first][cur.second] + 1;
						q.push({ curX, curY });
					}
				}
				
				for (int k = 0; k < N; ++k)
				{
					fill(dist[k], dist[k] + N, -1);
				}
				// �� �������� �ٸ� ������ ���� �Ÿ��� ���������Ƿ� ��� dist �ʱ�ȭ
			}
			// ���� ��� �����ϴ� bfs
		}
	}

	cout << minimumDist;

	return 0;
}