#include <iostream>

using namespace std;

const int INF = 9999999;
int dest[101][101];

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
				dest[i][j] = min(dest[i][j], dest[i][k] + dest[k][j]);
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

	return 0;
}
