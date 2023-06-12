#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
	}

	cout << *max_element(dp, dp + n);

	return 0;
}