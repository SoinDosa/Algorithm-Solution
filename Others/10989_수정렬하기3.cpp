#include <iostream>

using namespace std;

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int input = 0;

		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i < 10001; ++i)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		int cache = arr[i];

		for (int j = 0; j < cache; ++j)
		{
			cout << i << '\n';
		}
	}

	return 0;
}