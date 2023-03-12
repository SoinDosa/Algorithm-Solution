#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int V;
int E;
vector<pair<int, int>> adj[100005];
// { ���, ���� ��ȣ }
bool chk[10005];
// i��° ������ �ּ� ���� Ʈ���� ���� �ִ°�?

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
	// { ���, ����1, ����2 }

	chk[1] = true;
	for (auto nxt : adj[1])
	{
		pq.push({ nxt.first, 1, nxt.second });
	}
	// ���� ������ ����� ������ ��� �켱���� ť�� ��´�
	
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
// �����˰����� ���� Ǯ��