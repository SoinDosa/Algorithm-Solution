#include <iostream>

using namespace std;

int gcd(const int& a, const int& b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b % a, a);
}
// ��Ŭ���� ȣ������ ����� �ִ����� ���ϱ�

int lcm(const int& a, const int& b)
{
	return a / gcd(a, b) * b;
	// a * b / gcd(a,b)�� ���� �ʴ� ������ �����÷ο츦 �����ϱ� ������
}
// �ִ������� �̿��Ͽ� �ּҰ���� ���ϱ�

int solve(int M, int N, int x, int y)
{
	if (x == M)
	{
		x = 0;
	}

	if (y == N)
	{
		y = 0;
	}

	int l = lcm(M, N);
	
	for (int i = x; i <= l; i += M)
	{
		if (i == 0)
		{
			continue;
		}
		if (i % N == y)
		{
			return i;
		}
	}
	// �ð����⵵�� ���̱� ���� 1 ~ �ּҰ������ +1�� �˻����� �ʰ� +M ���ϸ鼭 �˻��Ѵ�

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int M, N, x, y;

		cin >> M >> N >> x >> y;
		cout << solve(M, N, x, y) << '\n';
	}

	return 0;
}