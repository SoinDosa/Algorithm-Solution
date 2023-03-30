#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;
int N, M, X;
vector<pair<int, int>> adj[1001];

int dijkstra(const int& st, const int& end)
{
	int dist[1001];
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	fill(dist, dist + N + 1, INF);

	dist[st] = 0;
	pq.push({ dist[st], st });
	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] != cur.first)
		{
			continue;
		}

		for (auto nxt : adj[cur.second])
		{
			if (dist[cur.second] + nxt.first >= dist[nxt.second])
			{
				continue;
			}

			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[cur.second] + nxt.first , nxt.second });
		}
	}

	return dist[end];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0;

	cin >> N >> M >> X;
	while (M--)
	{
		int u = 0, v = 0, w = 0;

		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	for (int st = 1; st <= N; ++st)
	{
		result = max(result, dijkstra(st, X) + dijkstra(X, st));
	}
	cout << result;

	return 0;
}