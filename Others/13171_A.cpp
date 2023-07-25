#include <iostream>
using namespace std;

const long long MOD = 1'000'000'007;

long long pow(long long num, long long ex)
{
	if (ex == 1)
	{
		return num % MOD;
	}

	long long val = pow(num, ex / 2);
	val = (val % MOD) * (val % MOD) % MOD;

	if (ex % 2 == 0)
	{
		return val;
	}
	return (val % MOD) * (num % MOD) % MOD;
}

int main()
{
	long long a, b;
	cin >> a >> b;
	cout << pow(a, b);
}