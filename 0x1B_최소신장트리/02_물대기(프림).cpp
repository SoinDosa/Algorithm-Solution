#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> adj[301];
// { 비용, 정점 }
bool chk[301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	int result = 0;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int cost = 0;

		cin >> cost;
		adj[i].push_back({ cost, 0 });
		adj[0].push_back({ cost, i });
	}
	// 가상의 정점 0을 이용해서 논에 우물을 파는 경우를 추가한다

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int cost = 0;
			
			cin >> cost;
			adj[i].push_back({ cost, j });
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	// { cost, u, v }

	chk[0] = true;
	for (auto nxt : adj[0])
	{
		pq.push({ nxt.first, 0, nxt.second });
	}

	while (cnt < N)
	{
		int u = 0;
		int v = 0;
		int cost = 0;

		tie(cost, u, v) = pq.top();
		pq.pop();

		if (chk[v] == true)
		{
			continue;
		}

		result += cost;
		cnt++;
		chk[v] = true;

		for (auto nxt : adj[v])
		{
			if (chk[nxt.second] == false)
			{
				pq.push({ nxt.first, v, nxt.second });
			}
		}
	}

	cout << result;

	return 0;
}
// 프림 알고리즘 풀이