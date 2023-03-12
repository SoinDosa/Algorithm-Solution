#include <iostream>
#include <vector>

using namespace std;

const int INF = 9999999;
int dest[101][101];
int nxt[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		fill(dest[i] + 1, dest[i] + 1 + N, INF);
	}
	while (M--)
	{
		int st = 0;
		int end = 0;
		int cost = 0;

		cin >> st >> end >> cost;
		dest[st][end] = min(dest[st][end], cost);
		nxt[st][end] = end;
	}
	for (int i = 1; i <= N; ++i)
	{
		dest[i][i] = 0;
	}
	// �⺻ ���̺� ����

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (dest[i][k] + dest[k][j] < dest[i][j])
				{
					dest[i][j] = dest[i][k] + dest[k][j];
					nxt[i][j] = nxt[i][k];
				}
				// ��� ������ ���� dest[i][k]�� ���ŵ� ��, nxt[i][j]�� nxt[i][k]�� ����
			}
		}
	}
	// ��� ��ҿ� �÷��̵� �˰��� ����

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (dest[i][j] == INF)
			{
				cout << "0 ";
			}
			else
			{
				cout << dest[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (dest[i][j] == 0 || dest[i][j] == INF)
			{
				cout << "0\n";
				continue;
			}
			// �� �� �ִ� ����� ���� �� 0 ���

			vector<int> path;
			int st = i;
			// i(�����)

			while (st != j)
			{
				path.push_back(st);
				st = nxt[st][j];
			}
			// st�� j(������)�� ���ϱ� ������ ��θ� vector�� push�Ѵ�
			path.push_back(j);
			// st�� j�� �ٴٸ��� while���� ���߹Ƿ� j�� ���� push
			cout << path.size() << ' ';
			for (auto x : path)
			{
				cout << x << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}