#include <iostream>

using namespace std;

long long Pow(long long a, long long b, long long c)
{
	if (b == 1)
	{
		return a % c;
	}

	long long value = Pow(a, b / 2, c);
	value = value * value % c;
	if (b % 2 == 0)
	{
		return value;
	}
	else
	{
		return value * a % c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A = 0;
	int B = 0;
	int C = 0;

	cin >> A >> B >> C;
	cout << Pow(A, B, C);

	return 0;
}