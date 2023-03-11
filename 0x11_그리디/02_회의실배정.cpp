#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> meetings[1000001];
// { end time, st time };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> meetings[i].second >> meetings[i].first;
	}
	sort(meetings, meetings + N);
	// 입력받은 회의를 빨리 끝나는 순서로, 끝나는 시간이 같다면 빨리 시작하는 순서로 정렬한다

	int result = 0;
	int t = 0;

	for (int i = 0; i < N; ++i)
	{
		if (t > meetings[i].second)
		{
			continue;
		}
		// 끝나는 시간보다 시작 시간이 빠른 회의는 패스
		result++;
		t = meetings[i].first;
		// 남은 회의들 중 끝나는 시간이 가장 빠른 회의를 넣는다
	}

	cout << result;

	return 0;
}