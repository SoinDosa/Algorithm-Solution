#include <iostream>

using namespace std;
const int MAX = 2000;

int n, m, r;
int items[101];
int dist[101][101];

void floyd()
{
	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
// 플로이드 연산

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; ++i)
	{
		fill(dist[i] + 1, dist[i] + n + 1, MAX);
	}
	for (int i = 1; i <= n; ++i)
	{
		dist[i][i] = 0;
	}
	// 거리테이블 초기화

	for (int i = 1; i <= n; ++i)
	{
		cin >> items[i];
	}

	while (r--)
	{
		int a = 0, b = 0, l = 0;

		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}
	floyd();
	
	int result = 0;
	for (int i = 1; i <= n; ++i)
	{
		int totalItem = 0;

		for (int j = 1; j <= n; ++j)
		{
			if (dist[i][j] > m)
			{
				continue;
			}
			totalItem += items[j];
		}

		result = max(result, totalItem);
	}
	// m을 넘어서는 거리의 아이템은 더하지않음

	cout << result;

	return 0;
}