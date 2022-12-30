#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long a = 0;
	long long b = 0;

	cin >> a >> b;

	if (a > b)
	{
		swap(a, b);
	}

	if (a == b || b - a == 1)
	{
		cout << 0;
	}
	else
	{
		cout << b - a - 1 << '\n';
		// a랑b가 같거나 1차이밖에 안날 떄를 고려해야함
	}

	for (long long i = a + 1; i < b; ++i)
	{
		cout << i << ' ';
	}

	return 0;
}