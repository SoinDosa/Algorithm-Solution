#include <iostream>

using namespace std;

pair<int, int> people[51];
int ranking[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	fill(ranking, ranking + N, 1);
	for (int i = 0; i < N; ++i)
	{
		int x = 0, y = 0;

		cin >> x >> y;
		people[i] = { x, y };
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			if (people[i].first < people[j].first && people[i].second < people[j].second)
			{
				ranking[i]++;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << ranking[i] << ' ';
	}

	return 0;
}