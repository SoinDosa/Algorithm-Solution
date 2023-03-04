#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int input[8];
int arr[8];

void func(const int& cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; ++i)
	{
		arr[cur] = input[i];
		func(cur + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}
	sort(input, input + N);

	func(0);

	return 0;
}