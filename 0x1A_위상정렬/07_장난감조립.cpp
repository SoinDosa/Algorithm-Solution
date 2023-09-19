#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> adj[101];
int indegree[101];
int cnt[101];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	while (M--) {
		int X, Y, K;
		cin >> X >> Y >> K;
		adj[X].push_back({ Y, K });
		indegree[Y]++;
	}

	queue<int> q;
	for (int i = N; i >= 1; --i) {
		if (indegree[i] == 0) {
			cnt[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (adj[cur].empty()) {
			continue;
		}

		for (auto nxt : adj[cur]) {
			cnt[nxt.first] += cnt[cur] * nxt.second;
			indegree[nxt.first]--;

			if (indegree[nxt.first] == 0) {
				q.push(nxt.first);
			}
		}
		cnt[cur] = 0;
	}
	
	for (int i = 1; i <= N; ++i) {
		if (cnt[i] == 0) {
			continue;
		}
		cout << i << ' ' << cnt[i] << '\n';
	}

	return 0;
}
// 위상정렬을 역으로 수행하면서 탐색하면 된다
