#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int hh, mm, ss;
	cin >> hh >> mm >> ss;

	int seconds;
	cin >> seconds;

	ss += seconds;
	mm += ss / 60;
	ss %= 60;
	hh += mm / 60;
	mm %= 60;
	hh %= 24;

	cout << hh << ' '  << mm << ' ' << ss;

	return 0;
}