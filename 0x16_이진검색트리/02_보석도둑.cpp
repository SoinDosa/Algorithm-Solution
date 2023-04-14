#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


pair<int, int> jewels[300001];
// { V, M }
multiset<int> bags;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> jewels[i].second >> jewels[i].first;
	}
	sort(jewels, jewels + N);

	while (K--)
	{
		int C;

		cin >> C;
		bags.insert(C);
	}
	
	long long result = 0;

	for (int i = N - 1; i >= 0; --i)
	{
		multiset<int>::iterator it = bags.lower_bound(jewels[i].second);
		// 가장 비싼 i번째 보석의 무게를 담을 수 있는 가방이 있는지 탐색

		if (it == bags.end())
		{
			continue;
		}
		// 맞는 무게의 가방이 없다면 스킵
		result += jewels[i].first;
		bags.erase(it);
		// 해당 가방은 사용되었단 의미이므로 제거
	}

	cout << result;

	return 0;
}