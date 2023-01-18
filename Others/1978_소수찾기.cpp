#include <iostream>

using namespace std;

bool isPrime[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int result = 0;

	fill(isPrime + 2, isPrime + 1001, true);
	for (int i = 2; i * i <= 1000; ++i)
	{
		if (isPrime[i] == true)
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	// 1 ~ 1000까지 에라토스테네스의 체 생성

	cin >> N;

	while (N--)
	{
		int input = 0;

		cin >> input;
		if (isPrime[input] == true)
		{
			result++;
		}
	}

	cout << result;

	return 0;
}