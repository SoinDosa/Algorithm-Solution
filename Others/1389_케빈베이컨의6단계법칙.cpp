#include <iostream>

using namespace std;

const int INF = 101;
int N, M;
int dist[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		fill(dist[i], dist[i] + 1 + N, INF);
		dist[i][i] = 0;
	}

	while (M--)
	{
		int u, v;

		cin >> u >> v;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int minVal = 0x7FFFFFFF;
	int result = 0;
	for (int i = N; i > 0; --i)
	{
		bool isAllConnected = true;
		int kabinBacon = 0;

		for (int j = 1; j <= N; ++j)
		{
			if (dist[i][j] == INF)
			{
				isAllConnected = false;
				break;
			}
			kabinBacon += dist[i][j];
		}

		if (!isAllConnected)
		{
			continue;
		}

		if (kabinBacon <= minVal)
		{
			minVal = kabinBacon;
			result = i;
		}
	}

	cout << result;

	return 0;
}