#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 0x3F33333333333333;

vector<pair<long long, int>> adj[100001];
int N, M, K;
vector<int> interviewZones;
long long dist[100001];

void dijkstra()
{
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
	fill(dist + 1, dist + 1 + N, INF);
	for (int z : interviewZones)
	{
		dist[z] = 0;
		pq.push({ 0, z });
	}
	while (!pq.empty())
	{
		long long curCost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curCost != dist[curNode])
		{
			continue;
		}

		for (pair<long long, int> nxt : adj[curNode])
		{
			if (dist[nxt.second] <= curCost + nxt.first)
			{
				continue;
			}
			dist[nxt.second] = curCost + nxt.first;
			pq.push({ dist[nxt.second], nxt.second });
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	while (M--)
	{
		int U, V;
		long long C;
		cin >> U >> V >> C;
		adj[V].push_back({ C, U });
	}
	while (K--)
	{
		int zone;
		cin >> zone;
		interviewZones.push_back(zone);
	}
	dijkstra();

	long long maxDist = 0;
	int maxFar = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (maxDist < dist[i])
		{
			maxFar = i;
			maxDist = dist[i];
		}
	}
	cout << maxFar << '\n' << maxDist;

	return 0;
}
