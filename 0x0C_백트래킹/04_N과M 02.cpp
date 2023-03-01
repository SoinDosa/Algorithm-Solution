#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int arr[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		arr[i] = 0;
	}

	for (int i = M; i < N; ++i)
	{
		arr[i] = 1;
	}

	do
	{
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] == 0)
			{
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	} 
	while (next_permutation(arr, arr + N));
	// next_permutation을 사용할때, arr은 int 배열이어야함

	return 0;
}