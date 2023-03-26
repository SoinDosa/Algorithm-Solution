#include <iostream>

using namespace std;

bool isPrime[1001];

void setPrime()
{
	fill(isPrime + 2, isPrime + 1001, true);

	for (int i = 2; i * i <= 1000; ++i)
	{
		if (isPrime[i] == false)
		{
			continue;
		}

		int num = i * 2;

		while (num <= 1000)
		{
			isPrime[num] = false;
			num += i;
		} 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int result = 0;

	setPrime();
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