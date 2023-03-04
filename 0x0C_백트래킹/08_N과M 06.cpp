#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int arr[10];
int permutation[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (i >= M)
		{
			permutation[i] = 1;
		}
	}

	sort(arr, arr + N);

	do
	{
		for (int i = 0; i < N; ++i)
		{
			if (permutation[i] == 0)
			{
				cout << arr[i] << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(permutation, permutation + N));
}