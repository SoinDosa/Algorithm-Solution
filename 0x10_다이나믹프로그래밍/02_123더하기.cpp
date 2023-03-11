#include <iostream>

using namespace std;

int dp[12];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; ++i)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	cin >> T;
	while (T--)
	{
		int input = 0;

		cin >> input;
		cout << dp[input] << '\n';
	}

	return 0;
}