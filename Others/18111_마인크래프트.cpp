#include <iostream>

using namespace std;

int board[501][501];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	long long B;
	int maxHeight = 0;
	int minHeight = 256;

	cin >> N >> M >> B;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] > maxHeight)
			{
				maxHeight = board[i][j];
			}

			if (board[i][j] < minHeight)
			{
				minHeight = board[i][j];
			}
		}
	}

	long long minTime = 99999999999;
	int perfectHeight = 0;
	for (int height = minHeight; height <= maxHeight; ++height)
	{
		long long cut = 0;
		long long rise = 0;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (board[i][j] > height)
				{
					cut += board[i][j] - height;
				}
				else if (board[i][j] < height)
				{
					rise += height - board[i][j];
				}
			}
		}

		if (B + cut >= rise)
		{
			long long totalTime = cut * 2 + rise;
			if (totalTime <= minTime)
			{
				minTime = totalTime;
				perfectHeight = height;
			}
		}
	}

	cout << minTime << ' ' << perfectHeight;
	return 0;
}