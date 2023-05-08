#include <iostream>

using namespace std;

long long dp[91];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	cin >> N;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= N; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	// 맨 뒷자리 수가 0이면 dp[i - 1] 을 0 앞에 붙인다
	// 맨 뒷자리 수가 01이면 dp[i - 2]를 01 앞에 붙이면 된다!

	cout << dp[N];

	return 0;
}