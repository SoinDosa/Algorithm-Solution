#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[101];
queue<int> q;
bool isInfested[101];
int result;

void BFS()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result++;

		for (int node : adj[cur])
		{
			if (isInfested[node] == true)
			{
				continue;
			}

			isInfested[node] = true;
			q.push(node);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int edgeCnt = 0;

	cin >> n >> edgeCnt;
	for (int i = 0; i < edgeCnt; ++i)
	{
		int u = 0;
		int v = 0;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);
	isInfested[1] = true;

	BFS();

	cout << result - 1;
}