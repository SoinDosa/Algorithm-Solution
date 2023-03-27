#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> p(10001, -1);
// �� ������ ��Ʈ�� ����, Union-Find ����
tuple<int, int, int> edge[100001];
// { cost, u, v }

int find(const int& x)
{
	if (p[x] < 0)
	{
		return x;
	}
	return p[x] = find(p[x]);
	// p[x]�� find(p[x])�� �����԰� ���ÿ� ��ȯ
	// [��� ����(Path Compression) ���], find ���� ����ȭ ���,
	// find �ϸ鼭 ���� ��� ���� �θ� ��带 ��Ʈ�� �����
}

bool isDiffGroup(int u, int v)
{
	u = find(u);
	v = find(v);
	// u, v�� ���� �ڽ��� ��Ʈ�� �ٲ۴�
	if (u == v)
	{
		return false;
	}
	// ��Ʈ�� �����Ƿ� ���� �׷�, false ��ȯ

	if (p[u] > p[v])
	{
		swap(u, v);
	}
	p[u] += p[v];
	p[v] = u;
	// Union-by-rank
	// ��Ʈ�� �������밪�� ������ ���� ���̰� �� ���� ����� �ǹ��̴� 

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
		// ������ ������ (���� ���� - 1) �� �Ǹ� MST�� �ϼ��� ���̹Ƿ� �ݺ��� ����
	}
	cout << result;

	return 0;
}