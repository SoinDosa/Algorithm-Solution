#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_DIST = 0x3F3F3F3F;
vector<pair<int, int>> adj[801];
long long dist[801][801];
// [시작점][도착점]
int N, E;

void dijkstra(const int& st)
{
	fill(dist[st], dist[st] + N + 1, MAX_DIST);

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st][st] = 0;
	pq.push({ dist[st][st], st });
	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (dist[st][cur.second] != cur.first)
		{
			continue;
		}

		for (pair<int, int> nxt : adj[cur.second])
		{
			if (dist[st][nxt.second] <= dist[st][cur.second] + nxt.first)
			{
				continue;
			}
			dist[st][nxt.second] = dist[st][cur.second] + nxt.first;
			pq.push({ dist[st][nxt.second], nxt.second });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> E;

	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	int v1, v2;
	cin >> v1 >> v2;
	dijkstra(1);
	dijkstra(v1);
	dijkstra(v2);

	long long dist1 = dist[1][v1] + dist[v1][v2] + dist[v2][N];
	long long dist2 = dist[1][v2] + dist[v2][v1] + dist[v1][N];

	long long result = min(dist1, dist2);
	if (result >= MAX_DIST)
	{
		result = -1;
	}
	cout << result;

	return 0;
}
// 오답정리 : longlong 자료형을 사용해야 올바른 값이 구해진다