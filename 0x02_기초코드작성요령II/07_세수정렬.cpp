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
	// min과 max는 braced-list로 사용할 수도 있고 algorithm헤더에 있다
	e = a + b + c - d - f;
	cout << d << ' ' << e << ' ' << f;

	return 0;
}