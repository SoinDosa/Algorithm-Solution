#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[501];
bool isVis[501];
int inviteCnt;

void bfs(const int& st)
{
	queue<pair<int, int>> q;
	// { value, near }

	q.push({ st, 0 });
	isVis[st] = true;
	
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.second > 2)
		{
			continue;
		}
		inviteCnt++;

		for (int e : adj[cur.first])
		{
			if (isVis[e])
			{
				continue;
			}

			isVis[e] = true;
			q.push({ e, cur.second + 1 });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs(1);
	cout << inviteCnt - 1;
	// 본인은 빼야함

	return 0;
}