#include <iostream>

using namespace std;

int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 0;
	int N = 0;
	int num = 2;

	cin >> M >> N;

	for (int i = 2; i <= N; ++i)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= N; ++i)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		for (int j = 2 * i; j <= N; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = M; i <= N; ++i)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		cout << arr[i] << '\n';
	}

	return 0;
}