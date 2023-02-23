#include <iostream>

using namespace std;

int paper[130][130];
int cnt[2];

bool isSameColor(int x, int y, int len)
{
	for (int i = x; i < x + len; ++i)
	{
		for (int j = y; j < y + len; ++j)
		{
			if (paper[x][y] != paper[i][j])
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
		cnt[paper[x][y]]++;
		return;
	}

	int n = len / 2;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			func(x + n * i, y + n * j, n);
		}
	}
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
			cin >> paper[i][j];
		}
	}
	func(0, 0, N);

	for (int i = 0; i < 2; ++i)
	{
		cout << cnt[i] << '\n';
	}
}