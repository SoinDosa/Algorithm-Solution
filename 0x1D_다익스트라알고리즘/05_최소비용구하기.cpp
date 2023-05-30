#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 0x3F3F3F3F;
int N, M;
vector<pair<int, int>> adj[1001];
// {cost, dest}
int dist[1001];
// �ִܰŸ� ���̺�

void dikstra(const int& st)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// ����� ���� �ͺ��� �;��ϹǷ� greater ����ü ���
	fill(dist + 1, dist + 1 + N, INF);

	dist[st] = 0;
	pq.push({ dist[st], st });

	while (!pq.empty())
	{
		pair<int, int> cur = pq.top();
		pq.pop();

		if (dist[cur.second] != cur.first)
		{
			continue;
		}

		for (pair<int, int> nxt : adj[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first)
			{
				continue;
			}
			dist[nxt.second] = dist[cur.second] + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	while (M--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
	}

	int A, B;
	cin >> A >> B;
	dikstra(A);

	cout << dist[B];

	return 0;
}