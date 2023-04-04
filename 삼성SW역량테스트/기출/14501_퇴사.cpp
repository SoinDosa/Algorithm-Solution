#include <iostream>
#include <algorithm>

using namespace std;

int dp[16];
int T[16];
int P[16];

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
			// dp[i + T[i]] + P[i] => i�Ͽ� ����� �ϸ� ���� �� �ִ� ����
			// dp[i + 1] => i�Ͽ� ����� ���ϸ� ���� �� �ִ� ����
		}
		// i�Ͽ� ����� �����Ѱ�?
		else
		{
			dp[i] = dp[i + 1];
		}
	}
	// �ڿ������� �ش��Ͽ� ����� �ϸ� ���� �� �ִ� �ִ� ������ ���

	cout << *max_element(dp, dp + N + 1);

	return 0;
}