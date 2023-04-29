#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(1001, -1);
tuple<long long, int, int> edges[1000001];
int N;

int find(const int& x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v)
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

	cin >> N;
	for (int i = 0; i < N * N; ++i)
	{
		long long cost;
		cin >> cost;
		edges[i] = { cost, i / N + 1, i % N + 1};
	}
	sort(edges, edges + N * N);

	long long result = 0;
	int cnt = 0;
	for (int i = 0; i < N * N; ++i)
	{
		int a, b;
		long long cost;
		tie(cost, a, b) = edges[i];

		if (!is_diff_group(a, b))
		{
			continue;
		}

		result += cost;
		cnt++;
		if (cnt == N - 1)
		{
			break;
		}
	}

	cout << result;

	return 0;
}