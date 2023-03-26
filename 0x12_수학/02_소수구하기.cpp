#include <iostream>

using namespace std;

bool isPrime[1000001];
int N;

void setPrime()
{
	fill(isPrime + 2, isPrime + N + 1, true);

	for (int i = 2; i * i <= N; ++i)
	{
		if (isPrime[i] == false)
		{
			continue;
		}

		int num = i * 2;

		while (num <= N)
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

	int M = 0;

	cin >> M >> N;
	setPrime();

	for (int i = M; i <= N; ++i)
	{
		if (isPrime[i] == true)
		{
			cout << i << '\n';
		}
	}

	return 0;
}