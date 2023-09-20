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
// { ��ǥ��, �༺��ȣ } ����
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
	// x,y,z ũ������� ������ ��, x,y,z ������ ������ 3���� edge�� �ִ´�

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
��� �༺ �� ������ ����ϰ� �����ϸ�
�־��� ��� �� 50�� ���� ���� ������ �����ؾ� �մϴ�.
���� �� �ʿ��� ���� ������ �߷��� ���� �ʿ��մϴ�.

i��° �༺�� ��ǥ ������ �޾�
pair<int, int> x, y, z �迭�� �����մϴ�.
�� �迭�� ��ǥ ���� �༺ ��ȣ�� ����մϴ�.

�� ��ǥ �迭���� �����ϸ�(47 - 49��° ��)
��ǥ�� ���̰� ���� ��ǥ ������ �յ� �ε����� �� �� �ֽ��ϴ�.
�̸� Ȱ���� ��ǥ �� ���� ���̸� ���밪���� ����� ������ ����� ����ϰ�,
������ �մ� �� �༺�� ��ȣ�� ���� ������ �Բ� �����մϴ�

���� ũ�罺Į �˰����� ����
���� ������ ��뿡 ���� ������������ �����ϰ�,
����� ���� �������� Ȯ���ϸ� MST�� �����մϴ�.
�� �������� ���� ����ġ ������ �ּڰ��� ����ϰ� �� ���� ������ ����մϴ�.
*/