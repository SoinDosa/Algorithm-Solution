#include <iostream>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;
	for (int i = N; i >= 1; --i) // ����� ���� ������ i�� �������� ���� �ٲ��ִ� ������� �ذ� ����
	{
		for (int j = 0; j < N - i; ++j)
		{
			cout << ' ';
		}

		for (int j = 0; j < 2 * i - 1; ++j)
		{
			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}