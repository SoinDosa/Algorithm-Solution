#include <iostream>
#include <vector>

using namespace std;

bool isPrime[40000001];
vector<int> primes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	if (N == 1)
	{
		cout << 0;
		return 0;
	}
	// ���� ���� : N�� 1�� ��츦 ������� ���� ��� �ϴܿ� sum = primes[0] �κп��� ��Ÿ�� ���� �߻�

	fill(isPrime + 2, isPrime + N + 1, true);

	for (int i = 2; i * i <= N; ++i)
	{
		if (!isPrime[i])
		{
			continue;
		}
		int cur = i + i;

		while (cur <= N)
		{
			isPrime[cur] = false;
			cur += i;
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}

	int primesCnt = primes.size();
	int en = 0;
	int sum = primes[0];
	int result = 0;

	for (int st = 0; st < primesCnt; ++st)
	{
		while (sum < N && en < primesCnt)
		{
			en++;
			if (en != primesCnt)
			{
				sum += primes[en];
			}
		}

		if (sum == N)
		{
			result++;
		}

		sum -= primes[st];
	}

	cout << result;

	return 0;
}