#include <iostream>

using namespace std;

void Hanoi(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}

	Hanoi(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	Hanoi(6 - a - b, b, n - 1);
}
// n���� ������ a��ġ���� b��ġ�� �ű��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	cout << (1 << N) - 1 << '\n';
	// 2^N - 1 ���
	Hanoi(1, 3, N);

	return 0;
}