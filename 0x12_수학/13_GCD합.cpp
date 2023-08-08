#include <iostream>
#include <vector>
using namespace std;

long long getGCD(long long a, long long b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return getGCD(b, a % b);
	}
}
// 유클리드 호제법
// 두 수가 있을 때 큰 수를 작은 수로 나눈나머지를 무한히 반복하다가 gcd(a, 0) 꼴이 되면 a가 최대 공약수이다

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		vector<long long> numbers;
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			long long input;
			cin >> input;
			numbers.push_back(input);
		}

		long long total = 0;
		// 왜 long long으로 해야 맞는가?
		// 모든 쌍(100 * 99 = 9900개)의 최대 공약수가 1000000일 경우 오버플로 발생
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				total += getGCD(numbers[i], numbers[j]);
			}
		}
		cout << total << '\n';
	}
}
