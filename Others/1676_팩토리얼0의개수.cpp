#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int cnt = 0;

	cin >> N;
	for (int i = 5; i <= N; i *= 5)
	{
		cnt += N / i;
	}
	// 500!�� �ſ� ũ�� ������ � �ڷ����� �ᵵ �Ұ���
	// �ڿ� 0�� ������ ���� 10�� ������ ���, 10 = 2 * 5�̹Ƿ� N!�� ���μ����� ���� �� ������ 2�� 5�� ������ �� ���� ����
	// ������ 5�� ������ �׻� �� �����Ƿ� 5�� ������ ���ϸ� ��
	// �μ��� 5�� ���� ���� �߰��ϸ� +1, 5*5�� ���� +2...

	cout << cnt;

	return 0;
}