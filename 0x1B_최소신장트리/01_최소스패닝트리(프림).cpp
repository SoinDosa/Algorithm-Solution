#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int V;
int E;
vector<pair<int, int>> adj[100005];
// { 비용, 정점 번호 }
bool chk[10005];
// i번째 정점이 최소 신장 트리에 속해 있는가?

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	int result = 0;

	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int u = 0;
		int v = 0;
		int cost = 0;

		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	// { 비용, 정점1, 정점2 }

	chk[1] = true;
	for (auto nxt : adj[1])
	{
		pq.push({ nxt.first, 1, nxt.second });
	}
	// 시작 정점과 연결된 간선을 모두 우선순위 큐에 담는다
	
	while (cnt < V - 1)
	{
		int cost = 0;
		int u = 0;
		int v = 0;

		tie(cost, u, v) = pq.top();

		pq.pop();
		if (chk[v] == true)
		{
			continue;
		}
		result += cost;
		chk[v] = true;
		cnt++;

		for (auto nxt : adj[v])
		{
			if (chk[nxt.second] == false)
			{
				pq.push({ nxt.first, v, nxt.second });
			}
		}
	}

	cout << result;

	return 0;
}
// 프림알고리즘을 통한 풀이