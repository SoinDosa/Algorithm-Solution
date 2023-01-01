#include <iostream>

using namespace std;

int N = 0;

void printStar(int i)
{
	for (int j = 0; j < N - i; ++j)
	{
		cout << ' ';
	}
	for (int j = 0; j < 2 * i - 1; ++j)
	{
		cout << '*';
	}
	cout << '\n';
}

int main()
{
	cin >> N;
	for (int i = N; i >= 1; --i)
	{
		printStar(i);
	}
	for (int i = 2; i <= N; ++i)
	{
		printStar(i);
	}

	return 0;
}