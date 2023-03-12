#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[1001];
bool isVisit[1001];
int N = 0;
int M = 0;
int V = 0;

void BFS()
{
	queue<int> q;

	q.push(V);
	isVisit[V] = true;
	while (!q.empty())
	{
		int cur = q.front();

		q.pop();
		cout << cur << ' ';
		for (auto nxt : adj[cur])
		{
			if (isVisit[nxt] == true)
			{
				continue;
			}

			q.push(nxt);
			isVisit[nxt] = true;
		}
	}
}

void DFS(int cur)
{
	isVisit[cur] = true;
	cout << cur << ' ';
	for (auto nxt : adj[cur])
	{
		if (isVisit[nxt] == true)
		{
			continue;
		}

		DFS(nxt);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i)
	{
		int u = 0;
		int v = 0;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for (int i = 1; i <= N; ++i)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	// 번호가 작은 것 부터 방문하기 위해 정렬

	DFS(V);
	cout << '\n';
	fill(isVisit + 1, isVisit + 1 + N, false);
	BFS();

	return 0;
}