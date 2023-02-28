#include <iostream>

using namespace std;

int arr[21];
int N;
int S;
int cnt;

void func(const int& len, const int& total)
{
	if (len == N)
	{
		if (total == S)
		{
			cnt++;
		}
		return;
	}

	func(len + 1, total);
	func(len + 1, total + arr[len]);
	// ������ ���̴� N�� ���� �ϰ�, arr�� �ش��ϴ� ���� ������, �ƴϸ� ������ ������ 2���� �б�� �����鼭 ���°���Ʈ�� ������
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	func(0, 0);
	if (S == 0)
	{
		cnt--;
	}
	// ũ�Ⱑ ����� �κм����� ���ٰ� ������ �������� ����
	// S�� 0�� ��쿡�� 1�� ���ָ� ��
	cout << cnt;

	return 0;
}