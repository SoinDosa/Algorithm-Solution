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
			// ���°���Ʈ���� len == M�� ������ ������ 
			isUsed[i] = false;
		}
	}
	// 1 ~ N ������ ���� �� ������ ���� ���ڰ� �ִ��� Ž��
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	func(0);

	return 0;
}