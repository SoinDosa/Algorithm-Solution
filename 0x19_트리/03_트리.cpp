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
		// nxt가 이전 노드와 동일할 경우 건너뛴다
		if (isVis[nxt] == true)
		{
			isTree = false;
			continue;
		}
		// 트리일 경우 자식노드는 이전에 방문한 적이 없었어야 하고
		// 이전에 방문을 했다면 연결된 노드들은 트리가 아니다

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
			// i를 트리의 루트로 두고 DFS 진행
			trees += isTree;
			// 트리라면 갯수 하나 추가
			// 단일 노드여도 트리로 친다
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