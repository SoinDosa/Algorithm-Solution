#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000001];
int parent[1000001];

void DFS(int cur)
{
	for (int nxt : adj[cur])
	{
		if (parent[cur] == nxt)
		{
			continue;
		}
		parent[nxt] = cur;
		DFS(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N - 1; ++i)
	{
		int u = 0;
		int v = 0;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DFS(1);
	for (int i = 2; i <= N; ++i)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}