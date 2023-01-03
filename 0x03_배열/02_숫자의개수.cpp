#include <iostream>

using namespace std;

int main()
{
	int A[3] = { 0, };
	int n[10] = { 0, };
	int result = 1;

	for (int i = 0; i < 3; ++i)
	{
		cin >> A[i];
		result *= A[i];
	}

	while (result != 0)
	{
		n[result % 10]++;
		result /= 10;
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << n[i] << '\n';
	}

	return 0;
}