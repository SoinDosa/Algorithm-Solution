#include <iostream>

using namespace std;

bool isPrime[250000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(isPrime + 2, isPrime + 250000, true);

	for (int i = 2; i * i < 250000; ++i)
	{
		if (!isPrime[i])
		{
			continue;
		}

		int temp = i * 2;
		while (temp < 250000)
		{
			isPrime[temp] = false;
			temp += i;
		}
	}

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			break;
		}

		int twiceN = n * 2;
		int cnt = 0;
		for (int i = n + 1; i <= twiceN; ++i)
		{
			if (isPrime[i])
			{
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}