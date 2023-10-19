#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
bool isLinked[201][201];
bool isVis[201];
vector<int> edges[201];
vector<int> path;

void input() {
	scanf("%d %d", &N, &M);

	int val;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &val);
			if (val == 0) {
				continue;
			}
			edges[i].push_back(j);
		}
	}
	
	for (int i = 0; i < M; ++i) {
		scanf("%d", &val);
		path.push_back(val);
	}
}

bool check_path() {
	int prevCity = path[0];
	for (int i = 1; i < M; ++i) {
		if (!isLinked[prevCity][path[i]]) {
			return false;
		}
	}
	return true;
}

void solution() {
	for (int i = 1; i <= N; ++i) {
		fill(isVis + 1, isVis + N + 1, false);

		queue<int> q;
		isVis[i] = true;
		isLinked[i][i] = true;
		// 오답정리 : 한 도시에서 동일한 도시를 다시 여행할 수 있으므로 꼭 넣어야함
		q.push(i);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int nxt : edges[cur]) {
				if (isVis[nxt]) {
					continue;
				}

				isLinked[i][nxt] = true;
				isVis[nxt] = true;
				q.push(nxt);
			}
		}
	}

	if (check_path()) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}

int main() {
	input();
	solution();

	return 0;
}
