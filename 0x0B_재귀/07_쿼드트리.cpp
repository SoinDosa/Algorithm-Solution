#include <iostream>

using namespace std;

char video[65][65];

bool isSameColor(int x, int y, int len)
{
	int xMax = x + len;
	int yMax = y + len;

	for (int i = x; i < xMax; ++i)
	{
		for (int j = y; j < yMax; ++j)
		{
			if (video[x][y] != video[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void func(int x, int y, int len)
{
	if (isSameColor(x, y, len))
	{
		cout << video[x][y];

		return;
	}

	int n = len / 2;

	cout << "(";

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			func(x + i * n, y + j * n, n);
		}
	}

	cout << ")";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> video[i][j];
		}
	}

	func(0, 0, N);

	return 0;
}