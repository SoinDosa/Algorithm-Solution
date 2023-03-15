#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 200001;
vector<pair<int, int>> adj[20001];
// { cost, dest }
int dist[20001];
// �ִܰŸ� ���̺� 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V = 0;
	int E = 0;
	int st = 0;

	cin >> V >> E >> st;
	fill(dist, dist + V + 1, INF);
	while (E--)
	{
		int u = 0;
		int v = 0;
		int w = 0;

		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ dist[st], st });
	// �������� �Ÿ�(0)�� �������� pq�� ����
	while (!pq.empty())
	{
		auto cur = pq.top();
		// ���� �Ÿ��� ���� ���� ����

		pq.pop();

		if (dist[cur.second] != cur.first)
		{
			continue;
		}
		// ���� ���� �ִ� ������ dist�� ���� ���� �ִ� �Ÿ��� �ٸ��ٸ� ����
		for (auto nxt : adj[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first)
			{
				continue;
			}
			// ���� ���� �ִ� ���������� �Ÿ� + ���� ��ұ����� �Ÿ��� ���� ������ұ����� �Ÿ����� ũ�� ����
			dist[nxt.second] = dist[cur.second] + nxt.first;
			// ���� ����� �Ÿ� ����
			pq.push({ dist[nxt.second], nxt.second });
		}
		// ���� ���� �ִ� ������ ������ ��Ҹ� pq�� ���� �ִ´�
	}

	for (int i = 1; i <= V; ++i)
	{
		if (dist[i] == INF)
		{
			cout << "INF\n";
		}
		else
		{
			cout << dist[i] << '\n';
		}
	}

	return 0;
}