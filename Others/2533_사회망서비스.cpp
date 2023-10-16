#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> edges[1000001];
bool isVis[1000001];
int dp[2][1000001];

void func(int cur) {
	isVis[cur] = true;
	dp[0][cur] = 1;
	for (int nxt : edges[cur]) {
		if (isVis[nxt]) {
			continue;
		}

		func(nxt);
		dp[1][cur] += dp[0][nxt];
		dp[0][cur] += min(dp[1][nxt], dp[0][nxt]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int u, v;
	for (int i = 0; i < N - 1; ++i) {
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	func(1);
	cout << min(dp[0][1], dp[1][1]);
}
