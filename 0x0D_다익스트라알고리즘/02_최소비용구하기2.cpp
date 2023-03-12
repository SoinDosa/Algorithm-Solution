#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000001;
vector<pair<int, int>> adj[1001];
// { cost, dest }
int dist[1001];
// �ִܰŸ� ���̺� 
int pre[1001];
// ���� ��ġ ���� ���̺�

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int m = 0;
	int st = 0;
	int en = 0;

	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	while (m--)
	{
		int u = 0;
		int v = 0;
		int w = 0;

		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	cin >> st >> en;

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
			pre[nxt.second] = cur.second;
			// ���ŵ� �� ���� ����� ���� ��ġ�� ���� ����
		}
		// ���� ���� �ִ� ������ ������ ��Ҹ� pq�� ���� �ִ´�
	}

	cout << dist[en] << '\n';

	vector<int> path;
	int cur = en;

	while (cur != st)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	// �������� �����Ͽ����Ƿ� �����´�
	cout << path.size() << '\n';
	for (auto x : path)
	{
		cout << x << ' ';
	}

	return 0;
}