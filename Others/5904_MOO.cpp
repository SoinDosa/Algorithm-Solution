#include <iostream>
using namespace std;

char moo[3] = { 'm', 'o', 'o' };

void func(int n, int k, int len)
{
	if (n <= 3)
	{
		cout << moo[n - 1];
		return;
	}
	// n�� 3���ϰ� �Ǹ� moo�� �°� ���

	int newLen = 2 * len + k + 3;
	// S(k + 1)�� ����

	if (newLen < n)
	{
		func(n, k + 1, newLen);
	}
	// ã������ ��ġ�� n���� ������ �� �� �� ����
	else
	{
		if (n > len && n <= len + k + 3)
		{
			if (n - len != 1)
			{
				cout << 'o';
			}
			else
			{
				cout << 'm';
			}
			return;
		}
		// ����� �ִ� ���ڿ�(���ӵ� o)�̶�� �°� ���
		else
		{
			func(n - (len + k + 3), 1, 3);
		}
		// �� �ܶ�� n�� S(k)��ŭ ���� �ٽ� ó������ Ž��
	}
}

int main()
{
	long long N;
	cin >> N;

	func(N, 1, 3);
	// ù ������ k = 1, ���̴� 3

	return 0;
}