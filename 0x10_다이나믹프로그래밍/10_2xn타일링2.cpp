#include <iostream>

using namespace std;

const int DIV = 10007;
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= 1000; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % DIV;
	}

	cout << dp[n];

	return 0;
}