#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, string>> v;

bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	while (N--)
	{
		int age;
		string name;

		cin >> age >> name;
		v.push_back({ age, name });
	}
	stable_sort(v.begin(), v.end(), cmp);

	for (pair<int, string> e : v)
	{
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}