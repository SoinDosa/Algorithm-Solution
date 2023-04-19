// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<pair<int, int>> flowers;
	// { 꽃이 피는 날, 꽃이 지는 날 }

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int startMon, startDay, endMon, endDay;

		cin >> startMon >> startDay >> endMon >> endDay;
		flowers.push_back({ startMon * 100 + startDay, endMon * 100 + endDay });
		// 이렇게 하면 3월 1일은 301, 11월 30일은 1130 식으로 저장
	}

	int t = 301;
	// 시작날짜, 3월 1일
	int result = 0;

	while (t < 1201)
	{
		int nxtT = t;

		for (int i = 0; i < N; ++i)
		{
			if (flowers[i].first <= t && flowers[i].second > nxtT)
			{
				nxtT = flowers[i].second;
			}
			// 모든 꽃 리스트를 체크하여 (현재 날짜보다 이르거나 같은 날짜에 피고, 늦게 지는 꽃을 탐색
		}

		if (nxtT == t)
		{
			cout << 0;
			return 0;
		}
		// 현재 날짜에서 전진이 불가능 = 빈 날짜가 생김, 만들 수 없음

		result++;
		t = nxtT;
	}
	// end날짜가 11월 30일이면 11월 30일엔 꽃이 핀게 아니다, 날짜 12월 1일까지 체크

	cout << result;

	return 0;
}
/*
우선 그리디한 관점에서 생각해보면 매번 현재 시점에서 피어있는 꽃 중에서
가장 마지막에 지는 꽃을 선택하면 된다.
3월 1일에서부터 11월 30일까지는 총 276일의 기간이니 모든 꽃이 하루만에 피었다가
진다 해도 최대 276개의 꽃을 선택하기만 하면 된다. 그렇기 때문에 그냥 매번 O(N)으로 
꽃을 선택하면 된다. 시간복잡도는 최악의 경우 O(276N)이다.
만약 문제가 3월 1일 to 11월 30일이 아니라 1일에서 1,000,000,000일 사이에서 꽃들을
정해야 하는 문제였다면 매번 O(N)으로 다음 꽃을 탐색하는 풀이는 최대 O(N^2)으로
시간초과일텐데 이 경우 어떻게 해결하면 좋을지 고민해보는걸 추천한다.
by 바킹독님
*/