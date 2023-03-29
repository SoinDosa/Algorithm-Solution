#include <iostream>

using namespace std;

const int MAX = 14;
int apart[MAX + 1][MAX + 1];

void setApart()
{
	for (int i = 1; i <= MAX; ++i)
	{
		apart[0][i] = i;
	}

	for (int i = 1; i <= MAX; ++i)
	{
		for (int j = 1; j <= MAX; ++j)
		{
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	setApart();
	while (T--)
	{
		int k = 0;
		int n = 0;

		cin >> k >> n;
		cout << apart[k][n] << '\n';
	}

	return 0;
}