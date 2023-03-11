#include <iostream>

using namespace std;

int dp[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int X = 0;

	cin >> X;

	dp[1] = 0;
	for (int i = 2; i <= X; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[X];
}