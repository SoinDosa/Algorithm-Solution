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
	// 오답 정리 : N이 1일 경우를 고려하지 않을 경우 하단에 sum = primes[0] 부분에서 런타임 에러 발생

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