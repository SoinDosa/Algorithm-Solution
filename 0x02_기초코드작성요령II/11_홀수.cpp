#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int minimum = 100;
	int sum = 0;
	bool isOdd = false;

	for (int i = 0; i < 7; ++i)
	{
		cin >> n;

		if (n & 1)
		// Ȧ���� ��� 1�� ��Ʈ AND ������ �ϸ� 1�� ������ �ƴϸ� 0�� ����
		{
			isOdd = true;
			sum += n;

			if (n < minimum)
			{
				minimum = n;
			}
		}
	}

	if (isOdd)
	{
		cout << sum << '\n' << minimum;
	}
	else
	{
		cout << -1;
	}

	return 0;
}