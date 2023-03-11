#include <iostream>
#include <vector>

using namespace std;

int score[301];
int dp[301][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> score[i];
	}

	if (n == 1)
	{
		cout << score[1];

		return 0;
	}

	dp[1][1] = score[1];
	dp[1][2] = 0;
	dp[2][1] = score[2];
	dp[2][2] = score[1] + score[2];

	for (int i = 3; i <= n; ++i)
	{
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
		dp[i][2] = dp[i - 1][1] + score[i];
	}

	cout << max(dp[n][1], dp[n][2]);

	return 0;
}