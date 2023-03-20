#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<int, long long>& a, const pair<int, long long>& b)
{
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	long long C = 0;
	vector<pair<int, long long>> v;
	// cnt, num

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		long long input = 0;
		bool isInVector = false;

		cin >> input;
		for (auto& e : v)
		{
			if (e.second == input)
			{
				isInVector = true;
				e.first++;
				break;
			}
		}
		if (isInVector == false)
		{
			v.push_back({ 1, input });
		}
	}
	stable_sort(v.begin(), v.end(), cmp);

	for (auto e : v)
	{
		for (int i = 0; i < e.first; ++i)
		{
			cout << e.second << ' ';
		}
	}

	return 0;
}