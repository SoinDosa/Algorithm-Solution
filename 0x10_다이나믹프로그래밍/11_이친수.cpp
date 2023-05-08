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
	// �� ���ڸ� ���� 0�̸� dp[i - 1] �� 0 �տ� ���δ�
	// �� ���ڸ� ���� 01�̸� dp[i - 2]�� 01 �տ� ���̸� �ȴ�!

	cout << dp[N];

	return 0;
}