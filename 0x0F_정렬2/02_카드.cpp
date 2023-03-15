#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	// 입력한 숫자를 오름차순으로 정렬

	int cnt = 0;
	// 현재 보고 있는 숫자가 연속해서 몇번 나왔는가?
	long long maxVal = -(1 << 62);
	// 가장 많은 수, 최소 숫자인 -2^62로 시작
	int maxCnt = 0;
	// 가장 많이 연속된 횟수
	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || arr[i - 1] == arr[i])
		{
			cnt++;
		}
		else
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				maxVal = arr[i - 1];
			}
			cnt = 1;
		}
		// 연속이 끊겼고 cnt가 maxCnt보다 크다면 maxCnt, maxVal을 갱신
		// >= 가 아니고 > 이므로 동일한 갯수의 큰 숫자로 갱신되지 않음
	}
	if (cnt > maxCnt)
	{
		maxVal = arr[N - 1];
	}
	// 제일 마지막 수가 몇 번 등장했는지를 별도로 확인

	cout << maxVal;

	return 0;
}