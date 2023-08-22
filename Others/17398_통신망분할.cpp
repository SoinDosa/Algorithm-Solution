#include <iostream>
#include <vector>
using namespace std;

int N, M, Q;
int roots[100001];
long long cnt[100001];
vector<pair<int, int>> connects;
bool isDisconnect[100001];
vector<int> del;

int find_root(int x)
{
	if (roots[x] == x)
	{
		return x;
	}
	return roots[x] = find_root(roots[x]);
}

void uni(int u, int v)
{
	u = find_root(u);
	v = find_root(v);

	if (u == v)
	{
		return;
	}

	if (u > v)
	{
		swap(u, v);
	}
	roots[v] = u;
	cnt[u] += cnt[v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; ++i)
	{
		roots[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		connects.push_back({ u, v });
	}

	for (int i = 0; i < Q; ++i)
	{
		int idx;
		cin >> idx;
		isDisconnect[idx - 1] = true;
		del.push_back(idx - 1);
	}

	for (int i = 0; i < M; ++i)
	{
		if (!isDisconnect[i])
		{
			uni(connects[i].first, connects[i].second);
		}
	}

	long long totalEnergy = 0;
	for (int i = del.size() - 1; i >= 0; --i)
	{
		int a = find_root(connects[del[i]].first);
		int b = find_root(connects[del[i]].second);

		if (a != b)
		{
			totalEnergy += cnt[a] * cnt[b];
		}
		uni(a, b);
	}

	cout << totalEnergy;
	return 0;
}
// 유니온 파인드를 역으로해서 푸는 문제였다
// 세상은 넓고 천재는 많구나...
