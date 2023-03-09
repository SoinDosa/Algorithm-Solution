#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int M;
int board[10][10];
int copiedBoard[10][10];
vector<pair<int, int>> cctv;
int blank;

void ApplyVision(int x, int y, int dir)
{
	dir %= 4;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M)
		{
			return;
		}
		
		if (copiedBoard[x][y] == 6)
		{
			return;
		}

		if (copiedBoard[x][y] != 0)
		{
			continue;
		}

		copiedBoard[x][y] = 7;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
			{
				cctv.push_back({ i, j });
			}
			// cctv의 위치를 벡터로 저장

			if (board[i][j] == 0)
			{
				blank++;
			}
			// board의 빈 공간 갯수 세기
		}
	}

	int totalDirCase = 1 << 2 * cctv.size();
	// 4진법을 플래그를 사용하여 모든 CCTV의 방향 경우의수를 검사할 것
	// 가능한 경우의 수는 4^cctv.size(), 시프트연산자로 표현하면 이와 같음 2^(2 * cctv.size()) -> 4^cctv.size()

	for (int dirCase = 0; dirCase < totalDirCase; ++dirCase)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				copiedBoard[i][j] = board[i][j];
			}
		}

		int dirFlag = dirCase;
		int totalBlank = 0;

		for (int i = 0; i < cctv.size(); ++i)
		{
			int dir = dirFlag % 4;
			// 플래그를 4로 나눈 나머지 즉, 가장 작은 자릿수
			dirFlag /= 4;
			// 그리고 4로 나눠줌

			int cctvX = cctv[i].first;
			int cctvY = cctv[i].second;

			if (board[cctvX][cctvY] == 1)
			{
				ApplyVision(cctvX, cctvY, dir);
			}
			else if (board[cctvX][cctvY] == 2)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 2);
			}
			else if (board[cctvX][cctvY] == 3)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
			}
			else if (board[cctvX][cctvY] == 4)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
				ApplyVision(cctvX, cctvY, dir + 2);
			}
			else
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
				ApplyVision(cctvX, cctvY, dir + 2);
				ApplyVision(cctvX, cctvY, dir + 3);
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (copiedBoard[i][j] == 0)
				{
					totalBlank++;
				}
			}
		}

		blank = min(blank, totalBlank);
	}

	cout << blank;

	return 0;
}