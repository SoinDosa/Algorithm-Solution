#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
// 0 1 2 3 상 하 좌 우
int N, M, K;
queue<tuple<int, int, int, int>> q;
// {x, y, virus, direction}
vector<pair<int, int>> board[101][101];

void move()
{
	while (!q.empty())
	{
		int x, y, v, d;
		tie(x, y, v, d) = q.front();
		q.pop();

		x += dx[d];
		y += dy[d];

		if (x < 1 || x >= N - 1 || y < 1 || y >= N - 1)
		{
			v /= 2;
			switch (d)
			{
			case 0:
				d = 1;
				break;
			case 1:
				d = 0;
				break;
			case 2:
				d = 3;
				break;
			case 3:
				d = 2;
				break;
			}
		}

		board[x][y].push_back({ v, d });
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j].size() <= 0)
			{
				continue;
			}

			if (board[i][j].size() > 1)
			{
				sort(board[i][j].begin(), board[i][j].end());
			}
			// 2개 이상 존재할 경우 가장 개체수가 많은 군집이 뒤로 오게 함
			int v = 0, d = 0;

			for (pair<int, int> cur : board[i][j])
			{
				v += cur.first;
				d = cur.second;
			}
			board[i][j].clear();
			q.push({ i, j, v, d });
		}
	}
	// 각 위치에 있는 미생물을 합치는 연산
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		while (K--)
		{
			int x, y, v, d;
			cin >> x >> y >> v >> d;
			q.push({ x, y, v, d - 1 });
		}

		while (M--)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					board[i][j].clear();
				}
			}

			move();
		}

		int result = 0;
		while (!q.empty())
		{
			result += get<2>(q.front());
			q.pop();
		}

		cout << '#' << test_case << ' ' << result << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}