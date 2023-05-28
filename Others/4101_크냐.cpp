#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		if (a > b)
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}

	return 0;
}
