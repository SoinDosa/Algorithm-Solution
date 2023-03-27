#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(301, -1);
int costs[301][301];
vector<tuple<int, int, int>> edges;
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

	int N = 0;
	int cnt = 0;
	int result = 0;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int cost = 0;

		cin >> cost;
		edges.push_back({ cost, 0, i });
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost = 0;

			cin >> cost;

			if (cost != 0)
			{
				edges.push_back({ cost, i, j });
			}
		}
	}
	sort(edges.begin(), edges.end());

	int edgesSize = edges.size();
	// 벡터 길이 캐싱
	for (int i = 0; i < edgesSize; ++i)
	{
		int u = 0;
		int v = 0;
		int cost = 0;

		tie(cost, u, v) = edges[i];
		
		if (isDiffGroup(u, v) == false)
		{
			continue;
		}

		result += cost;
		cnt++;

		if (cnt == N)
		{
			break;
		}
		// 우물을 파는 경우(가상의 정점)를 가정하므로 cnt는 N - 1이 아닌 N
	}

	cout << result;
}