#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int input[10];
int arr[10];
bool isUsed[10];

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

	for (int i = 0; i < N; ++i)
	{
		if (isUsed[i] == false)
		{
			isUsed[i] = true;
			arr[len] = input[i];
			func(len + 1);
			isUsed[i] = false;
		}
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
}