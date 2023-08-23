#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int board[1001][1001];
int N, M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int a;
			cin >> a;
			board[i][j] = a;
		}
	}
	int result = INT_MAX;
	int minNum = INT_MAX;
	priority_queue<pair<int, pair<int, int>>> pq;

	for (int i = 0; i < N; ++i)
	{
		sort(board[i], board[i] + M, greater<>());
		minNum = min(minNum, board[i][0]);
		pq.push({ board[i][0], { i, 0 } });
	}

	while (!pq.empty())
	{
		int maxNum = pq.top().first;
		int maxIndex = pq.top().second.first;
		int maxArrIdx = pq.top().second.second;
		pq.pop();

		result = min(result, maxNum - minNum);

		if (maxArrIdx + 1 >= M)
		{
			break;
		}
		minNum = min(minNum, board[maxIndex][maxArrIdx + 1]);
		pq.push({ board[maxIndex][maxArrIdx + 1], { maxIndex, maxArrIdx + 1 } });
	}
	cout << result;
}
