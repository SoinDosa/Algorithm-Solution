#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long reverseNumber(long long input)
{
	long long result = 0;
	long long num = 0;

	while (input > 0)
	{
		result *= 10;
		num = input % 10;
		input /= 10;
		result += num;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	vector<long long> v;

	cin >> n;
	while (n--)
	{
		long long input = 0;

		cin >> input;
		v.push_back(reverseNumber(input));
	}
	sort(v.begin(), v.end());

	for (auto e : v)
	{
		cout << e << '\n';
	}

	return 0;
}