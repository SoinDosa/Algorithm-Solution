#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[1001];
// {dist, v}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v, dist;
		cin >> u >> v >> dist;
		adj[u].push_back({ dist, v });
		adj[v].push_back({ dist, u });
	}

	while (M--)
	{
		queue<pair<int, int>> q;
		// {dist, v}
		vector<bool> isVis(N + 1);
		int dist = 0;
		int u, v;
		cin >> u >> v;

		isVis[u] = true;
		q.push({ 0, u });
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();

			if (cur.second == v)
			{
				cout << cur.first << '\n';
				break;
			}

			for (pair<int, int> nxt : adj[cur.second])
			{
				if (isVis[nxt.second] == true)
				{
					continue;
				}

				isVis[nxt.second] = true;
				q.push({cur.first + nxt.first, nxt.second});
			}
		}
	}

	return 0;
}
