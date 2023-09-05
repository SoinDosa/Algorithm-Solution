#include <iostream>
#include <vector>
using namespace std;

const int dx[6] = { -1, 0, 1, -1, 0, 1 };
const int dy[6] = { -1, -1, -1, 1, 1, 1 };

vector<int> evenRow[6401];
char board[81][81];
int N, M;
int totalSeat;
bool isVis[6401];
int prevLink[6401];

void init()
{
	totalSeat = 0;
	for (int i = 0; i < 6401; ++i)
	{
		evenRow[i].clear();
	}
	fill(prevLink, prevLink + 6401, -1);
}

void input()
{
	cin >> N >> M; 
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			char c;
			cin >> c;
			board[i][j] = c;

			if (c == '.')
			{
				++totalSeat;
			}
		}
	}
}

bool check_link(int x)
{
	for (int nxt : evenRow[x])
	{
		if (isVis[nxt])
		{
			continue;
		}

		isVis[nxt] = true;

		if (prevLink[nxt] == -1 || check_link(prevLink[nxt]))
		{
			prevLink[nxt] = x;
			return true;
		}
	}
	return false;
}

int solution()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board [i][j] == '.')
			{
				for (int dir = 0; dir < 6; ++dir)
				{
					int nxtX = i + dx[dir];
					int nxtY = j + dy[dir];

					if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M)
					{
						continue;
					}

					if (board[nxtX][nxtY] == 'x')
					{
						continue;
					}

					if (j % 2 == 0)
					{
						evenRow[i * M + j].push_back(nxtX * M + nxtY);
					}// 짝수일 때만 저장
				}
			}
		}
	}

	int cnt = 0;

	fill(isVis, isVis + 6401, false);
	for (int i = 0; i < N * M; ++i)
	{
		if (evenRow[i].empty())
		{
			continue;
		}

		if (check_link(i))
		{
			fill(isVis, isVis + 6401, false);
			++cnt;
		}
	}
	// 최대 매칭 이분그래프를 구한다

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int C;
	cin >> C;
	for (int tc = 1; tc <= C; ++tc)
	{
		init();
		input();
		cout << totalSeat - solution() << '\n';
		// 최대 좌석갯수 - 최대매칭간선의 갯수는 앉을 수 있는 자리의 수
	}
}