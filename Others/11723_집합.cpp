#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> us;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;

	cin >> M;
	while (M--)
	{
		string op;
		int num;

		cin >> op;
		
		if (op == "add")
		{
			cin >> num;
			us.insert(num);
		}
		else if (op == "remove")
		{
			cin >> num;
			us.erase(num);
		}
		else if (op == "check")
		{
			cin >> num;
			if (us.find(num) != us.end())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (op == "toggle")
		{
			cin >> num;
			if (us.find(num) != us.end())
			{
				us.erase(num);
			}
			else
			{
				us.insert(num);
			}
		}
		else if (op == "all")
		{
			for (int i = 1; i <= 20; ++i)
			{
				us.insert(i);
			}
		}
		else
		{
			us.clear();
		}
	}

	return 0;
}