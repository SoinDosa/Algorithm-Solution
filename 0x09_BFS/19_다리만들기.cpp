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
	// INT_MAX는 climits헤더를 선언해야 사용가능
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
				// 각 섬에 번호를 매겨서 board에 저장함, 이런 방법이!
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
						// 이미 거리가 측정된 곳이거나 같은 섬이라면 스킵

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
						// 다른 섬에 도달한 곳이 하나라도 있다면 최소 거리를 갱신하고 while문 중단

						dist[curX][curY] = dist[cur.first][cur.second] + 1;
						q.push({ curX, curY });
					}
				}
				
				for (int k = 0; k < N; ++k)
				{
					fill(dist[k], dist[k] + N, -1);
				}
				// 한 지점에서 다른 섬으로 가는 거리를 측정했으므로 모든 dist 초기화
			}
			// 섬일 경우 수행하는 bfs
		}
	}

	cout << minimumDist;

	return 0;
}