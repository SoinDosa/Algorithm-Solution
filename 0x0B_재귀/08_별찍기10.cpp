#include <iostream>

using namespace std;

bool star[2200][2200];

void fillStar(int x, int y)
{
	for (int i = x; i < x + 3; ++i)
	{
		for (int j = y; j < y + 3; ++j)
		{
			if (i == x + 1 && j == y + 1)
			{
				continue;
			}
			star[i][j] = true;
		}
	}
}

void func(int x, int y, int len)
{
	if (len == 3)
	{
		fillStar(x, y);
		return;
	}

	int n = len / 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == 1 && j == 1)
			{
				continue;
			}
			func(x + i * n, y + j * n, n);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	func(0, 0, N);

	for (int i = 0; i <= N; ++i)
	{
		for (int j = 0; j <= N; ++j)
		{
			if (star[i][j] == true)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}
}