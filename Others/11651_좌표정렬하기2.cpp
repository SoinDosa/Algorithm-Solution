#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	vector<pair<int, int>> v;

	cin >> N;
	while (N--)
	{
		int x, y;

		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), cmp);

	for (vector<pair<int, int>>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << it->first << ' ' << it->second << '\n';
	}

	return 0;
}