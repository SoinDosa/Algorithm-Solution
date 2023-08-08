#include <iostream>
using namespace std;

const int INF = 0x3F333333;

int costs[401][401];
int V, E;

int main()
{
	cin >> V >> E;
	for (int i = 1; i <= V; ++i)
	{
		fill(costs[i] + 1, costs[i] + 1 + V, INF);
		costs[i][i] = 0;
	}

	while (E--)
	{
		int st, en, c;
		cin >> st >> en >> c;
		costs[st][en] = c;
	}

	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				if (costs[i][j] > costs[i][k] + costs[k][j])
				{
					costs[i][j] = costs[i][k] + costs[k][j];
				}
			}
		}
	}

	int minDist = INF;
	for (int i = 1; i <= V - 1; ++i)
	{
		for (int j = i + 1; j <= V; ++j)
		{
			if (costs[i][j] == INF || costs[j][i] == INF)
			{
				continue;
			}
			int totalDist = costs[i][j] + costs[j][i];
			minDist = min(minDist, totalDist);
		}
	}

	if (minDist == INF)
	{
		cout << -1;
		return 0;
	}
  // 문제조건 제대로 보자!
	cout << minDist;
	return 0;
}
