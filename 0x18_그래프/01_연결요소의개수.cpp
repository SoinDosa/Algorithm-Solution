#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[1001];
bool isVisit[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;
	int cnt = 0;

	cin >> N >> M;
	while (M--)
	{
		int u = 0;
		int v = 0;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (isVisit[i] == true)
		{
			continue;
		}

		queue<int> q;

		cnt++;
		q.push(i);
		isVisit[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			
			q.pop();
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

	cout << cnt;

	return 0;
}