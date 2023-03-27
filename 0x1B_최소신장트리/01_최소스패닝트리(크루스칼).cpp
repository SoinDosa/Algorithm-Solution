#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(10001, -1);
// 각 정점의 루트를 저장, Union-Find 위함
tuple<int, int, int> edge[100001];
// { cost, u, v }

int find(const int& x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
	// p[x]에 find(p[x])를 대입함과 동시에 반환
	// [경로 압축(Path Compression) 기법], find 연산 최적화 기법,
	// find 하면서 만난 모든 값의 부모 노드를 루트로 만든다
}

bool isDiffGroup(int u, int v)
{
	u = find(u);
	v = find(v);
	// u, v를 각각 자신의 루트로 바꾼다
	if (u == v)
	{
		return false;
	}
	// 루트가 같으므로 같은 그룹, false 반환

	if (p[u] > p[v])
	{
		swap(u, v);
	}
	p[u] += p[v];
	p[v] = u;
	// Union-by-rank
	// 루트의 음수절대값이 높아질 수록 높이가 더 높은 노드라는 의미이다 

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int V = 0;
	int E = 0;
	int cnt = 0;
	int result = 0;
	
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int a = 0;
		int b = 0;
		int cost = 0;

		cin >> a >> b >> cost;
		edge[i] = { cost, a, b };
	}
	sort(edge, edge + E);

	for (int i = 0; i < E; ++i)
	{
		int a = 0;
		int b = 0;
		int cost = 0;

		tie(cost, a, b) = edge[i];

		if (isDiffGroup(a, b) == false)
		{
			continue;
		}

		result += cost;
		cnt++;
		if (cnt == V - 1)
		{
			break;
		}
		// 간선의 갯수가 (정점 갯수 - 1) 이 되면 MST가 완성된 것이므로 반복문 중지
	}
	cout << result;

	return 0;
}