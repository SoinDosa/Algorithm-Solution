#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
vector<int> adj[100001];
int parents[100001];
vector<int> childs[100001];
int treeSize[100001];

void make_tree(const int& currentNode, const int& parent)
{
	for (int child : adj[currentNode])
	{
		if (child != parent)
		{
			childs[currentNode].push_back(child);
			parents[child] = currentNode;
			make_tree(child, currentNode);
		}
	}
}

void count_subtree_nodes(const int& currentNode)
{
	treeSize[currentNode] = 1;
	for (int child : childs[currentNode])
	{
		count_subtree_nodes(child);
		treeSize[currentNode] += treeSize[child];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; ++i)
	{
		int U, V;
		cin >> U >> V;
		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	make_tree(R, -1);
	// 트리 생성
	count_subtree_nodes(R);
	// 모든 노드를 루트로 하는 서브트리의 크기 계산

	while (Q--)
	{
		int query;
		cin >> query;
		cout << treeSize[query] << '\n';
	}

	return 0;
}