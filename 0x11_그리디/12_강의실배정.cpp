#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> cla;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int s, t;
	for (int i = 0; i < N; ++i) {
		cin >> s >> t;
		cla.push_back({ s, t });
	}
	sort(cla.begin(), cla.end());

	priority_queue<int, vector<int>, greater<>> pq;
	for (pair<int, int> cur : cla) {
		if (pq.empty()) {
			pq.push(cur.second);
			continue;
		}

		if (pq.top() <= cur.first) {
			pq.pop();
			pq.push(cur.second);
		}
		else {
			pq.push(cur.second);
		}
	}

	cout << pq.size();
}
