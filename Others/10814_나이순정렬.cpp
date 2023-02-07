#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(tuple<int, string, int> a, tuple<int, string, int> b)
{
	if (get<0>(a) == get<0>(b))
	{
		return get<2>(a) < get<2>(b);
	}

	return get<0>(a) < get<0>(b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	vector<tuple<int, string, int>> members;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int age = 0;
		string name;

		cin >> age >> name;
		members.push_back({ age, name, i });
	}

	sort(members.begin(), members.end(), cmp);

	for (int i = 0; i < N; ++i)
	{
		int age = 0;
		string name;
		int _;
		tie(age, name, _) = members[i];

		cout << age << ' ' << name << '\n';
	}

	return 0;
}