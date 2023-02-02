#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };
int box[101][101][101];
int day[101][101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 0;
	int N = 0;
	int H = 0;
	int tomato = 0;
	int maxDay = 0;
	int allCount = 0;
	queue<tuple<int, int, int>> q;

	cin >> M >> N >> H;
	allCount = M * N * H;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			fill(day[i][j], day[i][j] + M, -1);
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					q.push({ i,j,k });
					day[i][j][k] = 0;
				}
				else if (box[i][j][k] == -1)
				{
					--allCount;
				}
			}
		}
	}

	while (!q.empty())
	{
		tuple<int, int, int> cur = q.front();

		q.pop();
		tomato++;
		for (int i = 0; i < 6; ++i)
		{
			int curX = get<0>(cur) + dx[i];
			int curY = get<1>(cur) + dy[i];
			int curZ = get<2>(cur) + dz[i];

			if (curX < 0 || curX >= H || curY < 0 || curY >= N || curZ < 0 || curZ >= M)
			{
				continue;
			}

			if (box[curX][curY][curZ] != 0)
			{
				continue;
			}

			if (day[curX][curY][curZ] != -1)
			{
				continue;
			}

			q.push({ curX, curY, curZ });
			day[curX][curY][curZ] = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			if (day[curX][curY][curZ] > maxDay)
			{
				maxDay = day[curX][curY][curZ];
			}
		}
	}

	if (tomato == allCount)
	{
		cout << maxDay;
	}
	else
	{
		cout << -1;
	}
	return 0;
}
// 깨달은점 : BFS를 수행하면 겹치는 구간이 생겨서 더 작음을 체크해줘야하지 않은가?
// BFS는 너비로 뻗어나가기 때문에 시작점이 여러 개여도 결국 중간지점에서 만난다