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
	// 기본 테이블 세팅

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
				// 경로 복원을 위해 dest[i][k]가 갱신될 때, nxt[i][j]를 nxt[i][k]로 변경
			}
		}
	}
	// 모든 요소에 플로이드 알고리즘 연산

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
			// 갈 수 있는 방법이 없을 때 0 출력

			vector<int> path;
			int st = i;
			// i(출발지)

			while (st != j)
			{
				path.push_back(st);
				st = nxt[st][j];
			}
			// st가 j(목적지)가 변하기 전까지 경로를 vector에 push한다
			path.push_back(j);
			// st가 j에 다다르면 while문이 멈추므로 j는 따로 push
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