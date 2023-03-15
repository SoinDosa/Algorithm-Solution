#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 100000001;
vector<pair<int, int>> adj[1001];
// { cost, dest }
int dist[1001];
// 최단거리 테이블 
int pre[1001];
// 이전 위치 저장 테이블

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int m = 0;
	int st = 0;
	int en = 0;

	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	while (m--)
	{
		int u = 0;
		int v = 0;
		int w = 0;

		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	cin >> st >> en;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[st] = 0;
	pq.push({ dist[st], st });
	// 시작점의 거리(0)과 시작점을 pq에 삽입
	while (!pq.empty())
	{
		auto cur = pq.top();
		// 가장 거리가 작은 원소 선택

		pq.pop();

		if (dist[cur.second] != cur.first)
		{
			continue;
		}
		// 현재 보고 있는 정점의 dist와 현재 보고 있는 거리가 다르다면 생략
		for (auto nxt : adj[cur.second])
		{
			if (dist[nxt.second] <= dist[cur.second] + nxt.first)
			{
				continue;
			}
			// 현재 보고 있는 정점까지의 거리 + 다음 요소까지의 거리가 기존 다음요소까지의 거리보다 크면 생략
			dist[nxt.second] = dist[cur.second] + nxt.first;
			// 다음 요소의 거리 갱신
			pq.push({ dist[nxt.second], nxt.second });
			pre[nxt.second] = cur.second;
			// 갱신될 때 다음 요소의 이전 위치는 현재 정점
		}
		// 현재 보고 있는 정점에 인접한 요소를 pq에 집어 넣는다
	}

	cout << dist[en] << '\n';

	vector<int> path;
	int cur = en;

	while (cur != st)
	{
		path.push_back(cur);
		cur = pre[cur];
	}
	path.push_back(cur);
	reverse(path.begin(), path.end());
	// 역순으로 삽입하였으므로 뒤집는다
	cout << path.size() << '\n';
	for (auto x : path)
	{
		cout << x << ' ';
	}

	return 0;
}