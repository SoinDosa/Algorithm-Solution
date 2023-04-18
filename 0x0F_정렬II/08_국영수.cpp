#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

vector<tuple<int, int, int, string>> scores;
// { lang, eng, mat, name }

bool cmp(const tuple<int, int, int, string>& a, const tuple<int, int, int, string>& b)
{
	if (get<0>(a) == get<0>(b))
	{
		if (get<1>(a) == get<1>(b))
		{
			if (get<2>(a) == get<2>(b))
			{
				return get<3>(a) < get<3>(b);
			}

			return get<2>(a) > get<2>(b);
		}

		return get<1>(a) < get<1>(b);
	}

	return get<0>(a) > get<0>(b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	while (N--)
	{
		string name;
		int lang, eng, mat;

		cin >> name >> lang >> eng >> mat;
		scores.push_back({ lang, eng, mat, name });
	}
	sort(scores.begin(), scores.end(), cmp);

	for (auto e : scores)
	{
		cout << get<3>(e) << '\n';
	}

	return 0;
}