#include <iostream>

using namespace std;

int coin[11];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int K = 0;
	int total = 0;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> coin[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		total += K / coin[i];
		K %= coin[i];
	}

	cout << total;

	return 0;
}