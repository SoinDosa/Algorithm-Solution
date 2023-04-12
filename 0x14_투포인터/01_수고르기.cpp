#include <iostream>
#include <algorithm>

using namespace std;

int A[100001];
int minResult = 0x7FFFFFFF;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	// A를 정렬해줘야함

	int en = 0;
	for (int st = 0; st < N; ++st)
	{
		while (en < N && A[en] - A[st] < M)
		{
			en++;
		}
		if (en == N)
		{
			break;
		}
		minResult = min(minResult, A[en] - A[st]);
	}

	cout << minResult;

	return 0;
}
// 이중for문을 사용할 경우 N^2의 시간복잡도, N = 100000, N^2 = 10000000000(100억) 이므로 시간초과