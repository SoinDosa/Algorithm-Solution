#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_NUM = 0x3FFFFFFF;
int moveTime[201][201];
vector<int> friends;
int N, M;
int K;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		fill(moveTime[i] + 1, moveTime[i] + 1 + N, MAX_NUM);
		moveTime[i][i] = 0;
	}
	while (M--)
	{
		int A, B, T;
		cin >> A >> B >> T;
		moveTime[A][B] = min(moveTime[A][B], T);
	}

	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				moveTime[i][j] = min(moveTime[i][j], moveTime[i][k] + moveTime[k][j]);
			}
		}
	}
	
	cin >> K;
	while (K--)
	{
		int input;
		cin >> input;
		friends.push_back(input);
	}

	vector<pair<int, int>> result;
	for (int i = 1; i <= N; ++i)
	{
		int mx = 0;
		for (int e : friends)
		{
			mx = max(mx, moveTime[i][e] + moveTime[e][i]);
		}
		result.push_back({ mx, i });
	}
	sort(result.begin(), result.end());
	// i에 갔다가 다시 돌아오는 시간을 모두 구한 후 오름차순으로 정렬

	int mn = result[0].first;
	for (pair<int, int> e : result)
	{
		if (mn < e.first)
		{
			break;
		}
		cout << e.second << ' ';
	}
	// result가 최소인 값들만 출력

	return 0;
}