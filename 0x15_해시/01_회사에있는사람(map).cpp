#include <iostream>
#include <map>

using namespace std;

map<string, bool, greater<string>> m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;

	cin >> n;
	while (n--)
	{
		string peopleName;
		string op;

		cin >> peopleName >> op;
		if (op == "enter")
		{
			m[peopleName] = true;
		}
		else
		{
			m[peopleName] = false;
		}
	}

	for (map<string, bool>::iterator it = m.begin(); it != m.end(); ++it)
	{
		if (it->second == true)
		{
			cout << it->first << '\n';
		}
	}

	return 0;
}