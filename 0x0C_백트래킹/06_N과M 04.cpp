#include <iostream>

using namespace std;

int N;
int M;
int arr[10];

void func(const int& len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (len == 0)
		{
			arr[len] = i;
			func(len + 1);
		}
		else
		{
			if (i >= arr[len - 1])
			{
				arr[len] = i;
				func(len + 1);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	func(0);
}