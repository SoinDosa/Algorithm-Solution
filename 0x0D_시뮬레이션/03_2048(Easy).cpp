#include <iostream>

using namespace std;

int N;
int board[21][21];
int copiedBoard[21][21];

void Rotate()
{
	int tmp[21][21] = {};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			tmp[i][j] = copiedBoard[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			copiedBoard[i][j] = tmp[N - j - 1][i];
		}
	}
}
// copiedBoard 회전

void Move(int dir)
{
	while (dir--)
	{
		Rotate();
	}

	for (int i = 0; i < N; ++i)
	{
		int moved[21] = {};
		int idx = 0;

		for (int j = 0; j < N; ++j)
		{
			if (copiedBoard[i][j] == 0)
			{
				continue;
			}

			if (moved[idx] == 0)
			{
				moved[idx] = copiedBoard[i][j];
			}
			else if (moved[idx] == copiedBoard[i][j])
			{
				moved[idx++] *= 2;
			}
			else
			{
				moved[++idx] = copiedBoard[i][j];
			}
			// 증감연산자 활용을 주목
		}

		for (int j = 0; j < N; ++j)
		{
			copiedBoard[i][j] = moved[j];
		}
	}
	// 한 행씩 확인하며 이동시킨다
}
// 회전하고 원상복구를 시키지 않는 이유는?
// 어차피 플래그를 통해 모든 방향의 경우의 수를 보는건 똑같기 때문

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int maxValue = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int dirFlag = 0; dirFlag < 1024; ++dirFlag)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				copiedBoard[i][j] = board[i][j];
			}
		}

		int brute = dirFlag;

		for (int i = 0; i < 5; ++i)
		{
			int dir = brute % 4;
			brute /= 4;
			Move(dir);
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				maxValue = max(maxValue, copiedBoard[i][j]);
			}
		}
	}

	cout << maxValue;

	return 0;
}