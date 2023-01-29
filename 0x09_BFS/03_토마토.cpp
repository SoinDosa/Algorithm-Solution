#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int box[1001][1001];
int day[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 0;
	int N = 0;
	int maxDay = 0;
	int emptyPoint = 0;
	int tomatoCount = 0;
	queue<pair<int, int>> q;

	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		fill(day[i], day[i] + M, -1);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
			{
				q.push({ i, j });
				day[i][j] = 0;
			}
			else if (box[i][j] == -1)
			{
				emptyPoint++;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		
		q.pop();
		tomatoCount++;
		for (int i = 0; i < 4; ++i)
		{
			int curX = cur.first + dx[i];
			int curY = cur.second + dy[i];

			if (curX < 0 || curX >= N || curY < 0 || curY >= M) 
			{
				continue;
			}

			if (box[curX][curY] == -1 || day[curX][curY] != -1)
			{
				continue;
			}

			day[curX][curY] = day[cur.first][cur.second] + 1;

			if (day[curX][curY] > maxDay)
			{
				maxDay = day[curX][curY];
			}

			q.push({ curX, curY });
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << day[i][j] << ' ';
		}
		cout << '\n';
	}

	if (tomatoCount < M * N - emptyPoint)
	{
		cout << -1;
	}
	// 익은 토마토의 갯수가 전체 판의 갯수 - 빈 공간보다 작을 경우 모든 토마토가 익은게 아님
	else
	{
		cout << maxDay;
	}

	return 0;
}