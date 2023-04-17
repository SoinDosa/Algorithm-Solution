#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int indegree[32001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;
	while (M--)
	{
		int u, v;

		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	queue<int> q;
	vector<int> result;

	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}
	// indegree�� 0�� �Ǵ� ������ �� ���̹Ƿ� ���� visüũ�� �� �ʿ�� ����

	for (int r : result)
	{
		cout << r << ' ';
	}

	return 0;
}