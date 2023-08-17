#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
pair<int, int> coords[1001];
vector<tuple<double, int, int>> edges;

// for union-find
vector<int> root(1001, -1);

int find(const int& x)
{
	if (root[x] < 0)
	{
		return x;
	}
	return root[x] = find(root[x]);
}

bool isDiffGroup(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
	{
		return false;
	}

	if (root[u] > root[v])
	{
		swap(u, v);
	}
	root[u] += root[v];
	root[v] = u;

	return true;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> coords[i].first >> coords[i].second;
	}

	int cnt = 0;
	while(M--)
	{
		int u, v;
		cin >> u >> v;

		if (!isDiffGroup(u, v))
		{
			continue;
		}
		++cnt;
	}

	for (int i = 1; i <= N - 1; ++i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			long long xGap = coords[i].first - coords[j].first;
			long long yGap = coords[i].second - coords[j].second;
			long long originDist = xGap * xGap + yGap * yGap;
			double dist = sqrt(originDist);
			edges.push_back({ dist, i, j });
		}
	}
	sort(edges.begin(), edges.end());

	double cost = 0;
	int curEdgeIdx = 0;
	while (curEdgeIdx < edges.size())
	{
		int st, en;
		double dist;
		tie(dist, st, en) = edges[curEdgeIdx++];

		if (!isDiffGroup(st, en))
		{
			continue;
		}

		cost += dist;
		++cnt;

		if (cnt == N - 1)
		{
			break;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << cost;
}
// 오답노트 : 좌표의 최대 길이가 100만이므로 dist를 구할 때 long long을 사용해야 했다
