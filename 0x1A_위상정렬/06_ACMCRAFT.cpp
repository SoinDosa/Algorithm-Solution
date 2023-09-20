#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, W;
int buildTimes[1001];
vector<int> adj[1001];
int indegree[1001];
int totalTime[1001];
// idx까지 도달하는데 필요한 시간

void input() {
	for (int i = 1; i <= N; ++i) {
		adj[i].clear();
		indegree[i] = 0;
		totalTime[i] = 0;
	}

	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> buildTimes[i];
	}
	while (K--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}
	cin >> W;
}

int solution() {
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur]) {
			totalTime[nxt] = max(totalTime[nxt], buildTimes[cur] + totalTime[cur]);
			indegree[nxt]--;

			if (indegree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	return totalTime[W] + buildTimes[W];
	// 최소 시간은 W까지 도달하는데 걸린 시간 + W 건설 시간
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		input();
		cout << solution() << '\n';
	}
}
