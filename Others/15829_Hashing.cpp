#include <iostream>

using namespace std;

const long long M = 1234567891;

int a[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	long long result = 0;
	long long r = 1;
	string input;

	cin >> L;
	cin >> input;
	for (int i = 0; i < L; ++i)
	{
		result = (result + (input[i] - 96) * r) % M;
		r = r * 31 % M;
	}

	cout << result;

	return 0;
}