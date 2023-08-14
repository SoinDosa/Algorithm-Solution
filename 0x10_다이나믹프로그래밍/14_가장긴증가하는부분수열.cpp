#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		dp[i] = 1;
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (A[j] < A[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp, dp + N);
}
