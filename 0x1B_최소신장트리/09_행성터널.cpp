// Authored by : scsc3204
// Co-authored by : -
// Commented by : Soindosa
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int N;
int roots[100001];
vector<pair<int, int>> x, y, z;
// { 좌표값, 행성번호 } 저장
vector<tuple<int, int, int>> edges;

int find(int x) {
	if (roots[x] < 0) {
		return x;
	}
	return roots[x] = find(roots[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) {
		return false;
	}
	
	if (roots[u] > roots[v]) {
		swap(u, v);
	}
	roots[u] += roots[v];
	roots[v] = u;

	return true;
}

void init() {
	cin >> N;
	fill(roots, roots + N, -1);

	for (int i = 0; i < N; ++i) {
		int ix, iy, iz;
		cin >> ix >> iy >> iz;
		x.push_back({ ix, i });
		y.push_back({ iy, i });
		z.push_back({ iz, i });
	}
}

void solution() {
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());
	// x,y,z 크기순으로 정렬한 후, x,y,z 축으로 근접한 3개만 edge에 넣는다

	for (int i = 1; i < N; ++i) {
		edges.push_back({ abs(x[i - 1].first - x[i].first), x[i - 1].second, x[i].second });
		edges.push_back({ abs(y[i - 1].first - y[i].first), y[i - 1].second, y[i].second });
		edges.push_back({ abs(z[i - 1].first - z[i].first), z[i - 1].second, z[i].second });
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;
	int totalDist = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int cost, u, v;
		tie(cost, u, v) = edges[i];

		if (!is_diff_group(u, v)) {
			continue;
		}
		totalDist += cost;
		cnt++;

		if (cnt == N - 1) {
			break;
		}
	}
	cout << totalDist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	solution();
}
/*
모든 행성 간 간선을 계산하고 저장하면
최악의 경우 약 50억 개의 간선 정보를 저장해야 합니다.
따라서 꼭 필요한 간선 정보만 추려낼 논리가 필요합니다.

i번째 행성의 좌표 정보를 받아
pair<int, int> x, y, z 배열에 저장합니다.
이 배열은 좌표 값과 행성 번호를 기록합니다.

이 좌표 배열들을 정렬하면(47 - 49번째 줄)
좌표의 차이가 적은 좌표 값들을 앞뒤 인덱스에 둘 수 있습니다.
이를 활용해 좌표 값 간의 차이를 절대값으로 계산해 간선의 비용을 계산하고,
간선이 잇는 두 행성의 번호를 간선 정보로 함께 저장합니다

이후 크루스칼 알고리즘을 따라
간선 정보를 비용에 대해 오름차순으로 정렬하고,
비용이 작은 간선부터 확인하며 MST를 구축합니다.
이 과정에서 간선 가중치 총합의 최솟값을 계산하고 그 값을 답으로 출력합니다.
*/