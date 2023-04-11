#include <iostream>

using namespace std;

int gcd(const int& a, const int& b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}
// 유클리드 호제법을 사용한 최대공약수 구하기

int lcm(const int& a, const int& b)
{
	return a / gcd(a, b) * b;
	// a * b / gcd(a,b)를 하지 않는 이유는 오버플로우를 방지하기 위함임
}
// 최대공약수를 이용하여 최소공배수 구하기

int solve(int M, int N, int x, int y)
{
	if (x == M)
	{
		x = 0;
	}

	if (y == N)
	{
		y = 0;
	}

	int l = lcm(M, N);
	
	for (int i = x; i <= l; i += M)
	{
		if (i == 0)
		{
			continue;
		}
		if (i % N == y)
		{
			return i;
		}
	}
	// 시간복잡도를 줄이기 위해 1 ~ 최소공배수를 +1씩 검사하지 않고 +M 씩하면서 검사한다

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int M, N, x, y;

		cin >> M >> N >> x >> y;
		cout << solve(M, N, x, y) << '\n';
	}

	return 0;
}