#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N = 0;
	int result = 0;
	long long devider = 0;

	cin >> N;
	N -= 1;
	result++;
	while (N > 0)
	{
		devider += 6;
		N -= devider;
		result++;
	}

	cout << result;

	return 0;
}