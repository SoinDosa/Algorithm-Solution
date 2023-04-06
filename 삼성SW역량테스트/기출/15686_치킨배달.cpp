#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int village[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int minChickenDist = 0x7FFFFFFF;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> village[i][j];
			if (village[i][j] == 1)
			{
				house.push_back({ i, j });
			}
			else if (village[i][j] == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + M, 0);
	// next_permutation 사용을 위한 vector
	// 치킨집이 많으면 많을수록 도시의 치킨거리가 줄어드므로 무조건 최대 갯수인 M개를 살린다
	do
	{
		int dist = 0;

		for (auto h : house)
		{
			int tmp = 0x7FFFFFFF;
			for (int i = 0; i < chicken.size(); ++i)
			{
				if (brute[i] == 1)
				{
					continue;
				}
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
			// 최소 치킨거리 = 한 집의 치킨거리
		}
		minChickenDist = min(minChickenDist, dist);
		// 최소 치킨거리 갱신
	} while (next_permutation(brute.begin(), brute.end()));

	cout << minChickenDist;

	return 0;
}