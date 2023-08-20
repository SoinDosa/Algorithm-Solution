#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N, M, K;
// { cost, v }
bool isEnergy[1001];
vector<int> energies;
bool isConnected[1001];
vector<pair<int, int>> adj[1001];

bool check_all_connect()
{
	for (int i = 1; i <= N; ++i)
	{
		if (isEnergy[i])
		{
			continue;
		}

		if (!isConnected[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	while (K--)
	{
		int num;
		cin >> num;
		isEnergy[num] = true;
		energies.push_back(num);
	}

	
	while (M--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	for (int e : energies)
	{
		isConnected[e] = true;
		for (pair<int, int> nxt : adj[e])
		{
			pq.push({ nxt.first, e, nxt.second });
		}
	}

	int total = 0;
	while (!pq.empty())
	{
		int curW, curU, curV;
		tie(curW, curU, curV) = pq.top();
		pq.pop();

		if (isConnected[curV])
		{
			continue;
		}

		total += curW;
		isConnected[curV] = true;
		if (check_all_connect())
		{
			break;
		}

		for (pair<int, int> nxt : adj[curV])
		{
			if (isConnected[nxt.second])
			{
				continue;
			}
			pq.push({ nxt.first, curV, nxt.second });
		}
	}
	
	cout << total;
}