#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[11][11];
vector<int> comb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		if (i != K)
		{
			comb.push_back(i);
		}
	}
	// 시작지점을 제외한 모든 행성의 번호를 순열에 넣는다

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> dist[i][j];
		}
	}

	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	// 플로이드 알고리즘으로 모든 행성에서 모든 행성으로의 최단거리 계산

	int minTime = 0x7FFFFFFF;
	do
	{
		int tmp = dist[K][comb[0]];
		// 각 경우의 수의 총 여행시간
		for (int i = 1; i < N - 1; ++i)
		{
			tmp += dist[comb[i - 1]][comb[i]];
		}
		minTime = min(minTime, tmp);
	} while (next_permutation(comb.begin(), comb.end()));
	// 행성을 지나가는 모든 경우의 수를 순열로 탐색
	// 시작지점은 고정되어 있다

	cout << minTime;

	return 0;
}
// 오답정리
// 모든 거리를 플로이드로 정하고 행성마다 최소거리를 선택하는 방식은 틀림