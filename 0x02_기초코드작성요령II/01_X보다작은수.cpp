#include <iostream>

using namespace std;

int main()
{
	int N = 0, X = 0;
	int A = 0;

	cin >> N >> X;
	for (int i = 0; i < N; ++i)
	{
		cin >> A;
		if (A < X)
		{
			cout << A << ' ';
		}
	}

	return 0;
}