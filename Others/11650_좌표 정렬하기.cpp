#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	vector<pair<int, int>> v;

	cin >> N;
	while (N--)
	{
		int x = 0;
		int y = 0;

		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}