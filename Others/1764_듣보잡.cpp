#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<string, pair<bool, bool>> mem;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;
	while (N--)
	{
		string name;

		cin >> name;
		mem[name].first = true;
	}

	while (M--)
	{
		string name;

		cin >> name;
		mem[name].second = true;
	}

	vector<pair<string, pair<bool, bool>>> v(mem.begin(), mem.end());
	vector<string> names;

	for (auto e : v)
	{
		if (e.second.first && e.second.second)
		{
			names.push_back(e.first);
		}
	}
	sort(names.begin(), names.end());

	cout << names.size() << '\n';
	for (auto e : names)
	{
		cout << e << '\n';
	}

	return 0;
}