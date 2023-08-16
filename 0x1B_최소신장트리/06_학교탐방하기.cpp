#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
vector<int> root(1001, -1);
vector<tuple<int, int, int>> edges;

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	int A, B, C;
	cin >> A >> B >> C;
	edges.push_back({ C, A, B });

	while (M--)
	{
		cin >> A >> B >> C;
		edges.push_back({ C, A, B });
	}
	sort(edges.begin(), edges.end(), greater<>());

	int minTired = 0;
	int cnt = 0;
	for (auto e : edges)
	{
		int st, en, isOne;
		tie(isOne, st, en) = e;

		if (!isDiffGroup(st, en))
		{
			continue;
		}

		if (!isOne)
		{
			++minTired;
		}

		++cnt;
		if (cnt == N)
		{
			break;
		}
	}

	root = vector<int>(1001, -1);
	reverse(edges.begin(), edges.end());
	int maxTired = 0;
	cnt = 0;
	for (auto e : edges)
	{
		int st, en, isOne;
		tie(isOne, st, en) = e;

		if (!isDiffGroup(st, en))
		{
			continue;
		}

		if (!isOne)
		{
			++maxTired;
		}

		++cnt;
		if (cnt == N)
		{
			break;
		}
	}

	minTired *= minTired;
	maxTired *= maxTired;

	cout << maxTired - minTired;
}
// 오답노트 : w가 0일때 오르막길이었어...
