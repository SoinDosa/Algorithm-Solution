#include <iostream>
using namespace std;

int s, N, K, R1, R2, C1, C2;

int func(int len, int x, int y)
{
	if (len == 1)
	{
		return 0;
	}

	int border = len / N;

	if (x >= border * (N - K) / 2 && x < border * (N + K) / 2 && y >= border * (N - K) / 2 && y < border * (N + K) / 2)
	{
		return 1;
	}
	// �� ���� ���̰� l�� ����� ��� k * k ������ �������� ��� ������

	return func(border, x % border, y % border);
}
// len���� ��ü ����� ���� ���̰� �����

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = 1;
	while (s--)
	{
		len *= N;
	}

	for (int i = R1; i <= R2; ++i)
	{
		for (int j = C1; j <= C2; ++j)
		{
			cout << func(len, i, j);
		}
		cout << '\n';
	}
}
// n�� s�� �̿��Ͽ� �̸� ��ü ����� �� ���� ���̸� ���ϰ�
// ���� for���� �̿��Ͽ� �� r1, r2, �� c1, c2 ������ ������ �ϳ��� �����Ͽ� ���
