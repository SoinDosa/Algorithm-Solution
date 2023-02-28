#include <iostream>

using namespace std;

int N;
int cnt;
bool isUsed1[30];
// ���� ��
bool isUsed2[30];
bool isUsed3[30];
// ���� �밢��


void func(const int& curX)
{
	if (curX == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (isUsed1[i] || isUsed2[i + curX] || isUsed3[curX - i + N - 1])
		{
			continue;
		}
		// ������ ����� ���� ���ٸ� continue�� �ϴٰ� return��

		isUsed1[i] = true;
		isUsed2[i + curX] = true;
		isUsed3[curX - i + N - 1] = true;
		func(curX + 1);
		isUsed1[i] = false;
		isUsed2[i + curX] = false;
		isUsed3[curX - i + N - 1] = false;
	}
	// i�� y(��)�� �ǹ�
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	func(0);

	cout << cnt;
}