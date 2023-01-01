#include <iostream>

using namespace std;

int N = 0;

void printStar(int i)
{
	for (int j = 0; j < i; ++j)
	{
		cout << '*';
	}
	for (int j = 0; j < 2 * (N - i); ++j)
	{
		cout << ' ';
	}
	for (int j = 0; j < i; ++j)
	{
		cout << '*';
	}
	cout << '\n';
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		printStar(i);
	}
	for (int i = N - 1; i >= 1; --i)
	{
		printStar(i);
	}

	return 0;
}