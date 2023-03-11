#include <iostream>

using namespace std;

int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		if (i == 1)
		{
			cin >> dp[i];
			continue;
		}

		int input = 0;
		
		cin >> input;
		dp[i] = dp[i - 1] + input;
	}

	while (M--)
	{
		int st = 0;
		int dest = 0;

		cin >> st >> dest;
		cout << dp[dest] - dp[st - 1] << '\n';
	}

	return 0;
}