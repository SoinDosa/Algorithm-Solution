// Authored by : heheHwang
// Co-authored by : -
// Commented by : Soindosa
// http://boj.kr/3152615450164f11968c6f80dc779569
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
bool isVis[501];
bool isTree;

void DFS(int cur, int prev)
{
	for (int nxt : adj[cur])
	{
		if (nxt == prev)
		{
			continue;
		}
		// nxt�� ���� ���� ������ ��� �ǳʶڴ�
		if (isVis[nxt] == true)
		{
			isTree = false;
			continue;
		}
		// Ʈ���� ��� �ڽĳ��� ������ �湮�� ���� ������� �ϰ�
		// ������ �湮�� �ߴٸ� ����� ������ Ʈ���� �ƴϴ�

		isVis[nxt] = true;
		DFS(nxt, cur);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCase = 0;

	while (true)
	{
		int n = 0;
		int m = 0;
		int trees = 0;

		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}

		fill(isVis, isVis + n + 1, false);
		for (int i = 1; i <= n; ++i)
		{
			adj[i].clear();
		}

		while (m--)
		{
			int u = 0;
			int v = 0;

			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; ++i)
		{
			if (isVis[i] == true)
			{
				continue;
			}
			isVis[i] = true;
			isTree = true;
			DFS(i, -1);
			// i�� Ʈ���� ��Ʈ�� �ΰ� DFS ����
			trees += isTree;
			// Ʈ����� ���� �ϳ� �߰�
			// ���� ��忩�� Ʈ���� ģ��
		}

		cout << "Case " << ++testCase << ": ";
		if (trees == 0)
		{
			cout << "No trees.\n";
		}
		else if (trees == 1)
		{
			cout << "There is one tree.\n";
		}
		else
		{
			cout << "A forest of " << trees << " trees.\n";
		}
	}
	
	return 0;
}