#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(100001, -1);
tuple<int, int, int> edge[1000001];
// { cost, u, v }

int find(const int& x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
}

bool isDiffGroup(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
	{
		return false;
	}

	if (p[u] > p[v])
	{
		swap(u, v);
	}
	p[u] += p[v];
	p[v] = u;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int cost, u, v;
		cin >> u >> v >> cost;
		edge[i] = { cost, u, v };
	}
	sort(edge, edge + M);

	int result = 0;
	int maxCost = 0;
	int cnt = 0;
	for (int i = 0; i < M; ++i)
	{
		int u, v, cost;
		tie(cost, u, v) = edge[i];

		if (isDiffGroup(u, v) == false)
		{
			continue;
		}

		cnt++;
		result += cost;
		maxCost = max(maxCost, cost);
		// 최소스패닝트리를 만든 후
		// 그 안에서 가장 크기가 큰 간선을 없애면
		// 나머지 길의 유지비의 합이 최소가 됨

		if (cnt == N - 1)
		{
			break;
		}
	}

	cout << result - maxCost;

	return 0;
}
