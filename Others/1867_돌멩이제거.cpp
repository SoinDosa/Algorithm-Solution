#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> adj[501];
int prevNode[501];
bool isVis[501];

bool connect_check(int x)
{
	for (int nxt : adj[x])
	{
		if (isVis[nxt])
		{
			continue;
		}

		isVis[nxt] = true;

		if (prevNode[nxt] == 0 || connect_check(prevNode[nxt]))
		{
			prevNode[nxt] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	while (k--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	int cnt = 0;
	for (int i = 1; i <= 500; ++i)
	{
		if (adj[i].empty())
		{
			continue;
		}

		if (connect_check(i))
		{
			fill(isVis, isVis + 501, false);
			++cnt;
		}
	}
	cout << cnt;
}
