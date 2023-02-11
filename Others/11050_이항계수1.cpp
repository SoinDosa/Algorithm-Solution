#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int K = 0;
	int a = 1;
	int b = 1;
	int c = 1;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		a *= i;
	}

	for (int i = 1; i <= N - K; ++i)
	{
		b *= i;
	}

	for (int i = 1; i <= K; ++i)
	{
		c *= i;
	}

	cout << a / (b * c);

	return 0;
}