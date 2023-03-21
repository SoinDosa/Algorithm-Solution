#include <iostream>

using namespace std;

int dp0[41];
int dp1[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;

	dp0[0] = 1;
	dp0[1] = 0;
	dp1[0] = 0;
	dp1[1] = 1;

	for (int i = 2; i < 41; ++i)
	{
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}
	// 0 ~ 40 까지의 값을 미리 구함

	while (T--)
	{
		int N = 0;
		
		cin >> N;
		cout << dp0[N] << ' ' << dp1[N] << '\n';
	}

	return 0;
}