#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	int d = 0, e = 0, f = 0;

	cin >> a >> b >> c;
	d = min({ a, b, c });
	f = max({ a, b, c });
	// min�� max�� braced-list�� ����� ���� �ְ� algorithm����� �ִ�
	e = a + b + c - d - f;
	cout << d << ' ' << e << ' ' << f;

	return 0;
}