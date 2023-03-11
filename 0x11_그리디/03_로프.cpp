#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int maxWeight = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> rope[i];
	}
	sort(rope, rope + N, greater<int>());
	// 로프를 강한 순서대로 정렬

	for (int i = 0; i < N; ++i)
	{
		maxWeight = max(maxWeight, rope[i] * (i + 1));
	}
	// 강한 순서대로 버틸 수 있는 무게를 늘려가며 체크
	// 최대 중량을 구하려면 약한 로프는 필요 없을 지언정, 가장 강한 로프의 사용은 필수이다

	cout << maxWeight;

	return 0;
}