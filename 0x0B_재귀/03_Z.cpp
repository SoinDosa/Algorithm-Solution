#include <iostream>

using namespace std;

int Z(int n, int r, int c)
{
	if (n == 0)
	{
		return 0;
	}

	int half = 1 << (n - 1);
	// 2^n-1

	if (r < half && c < half)
	{
		return Z(n - 1, r, c);
	}
	else if (r < half && c >= half)
	{
		return half * half + Z(n - 1, r, c - half);
	}
	else if (r >= half && c < half)
	{
		return 2 * half * half + Z(n - 1, r - half, c);
	}
	else
	{
		return 3 * half * half + Z(n - 1, r - half, c - half);
	}
	// ���� 1, 2, 3, 4 �� �簢����
	// �簢�� ��ġ�� ���� r, c���� half��ŭ�� ���༭ ���� ��������� ��Ȯ�ϰ� ã�� �� �ִ�
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int r;
	int c;

	cin >> N >> r >> c;
	cout << Z(N, r, c);
}