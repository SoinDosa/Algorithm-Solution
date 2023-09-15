#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500001];
int T[1500001];
int P[1500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; --i)
	{
		if (i + T[i] <= N + 1)
		{
			dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
			// dp[i + T[i]] + P[i] => i일에 상담을 하면 얻을 수 있는 수익
			// dp[i + 1] => i일에 상담을 안하면 얻을 수 있는 수익
		}
		// i일에 상담이 가능한가?
		else
		{
			dp[i] = dp[i + 1];
		}
	}
	// 뒤에서부터 해당일에 상담을 하면 얻을 수 있는 최대 수익을 계산

	cout << *max_element(dp, dp + N + 1);

	return 0;
}
