#include <iostream>

using namespace std;

int N;
int M;
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

	for (int i = 1; i <= N; ++i)
	{
		if (!isUsed[i])
		{
			arr[len] = i;
			isUsed[i] = true;
			func(len + 1);
			// 상태공간트리를 len == M일 때까지 내려감 
			isUsed[i] = false;
		}
	}
	// 1 ~ N 까지의 숫자 중 사용되지 않은 숫자가 있는지 탐색
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	func(0);

	return 0;
}