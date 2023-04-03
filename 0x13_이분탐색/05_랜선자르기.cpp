#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int arr[10001];

bool isGetLan(const long long& x)
{
	long long cur = 0;
	for (int i = 0; i < K; ++i)
	{
		cur += arr[i] / x;
	}

	return cur >= N;
}
// 길이 x로 잘랐을 때 원하는 갯수의 랜선을 얻을 수 있는지 확인

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> N;
	for (int i = 0; i < K; ++i)
	{
		cin >> arr[i];
	}

	long long st = 1;
	long long en = (1 << 31) - 1;
	// 2^31 - 1;

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		// (st + en) / 2로 둘 경우 st와 en이 1이 차이날 때 st가 계속 값이 똑같아버릴 수 있음

		if (isGetLan(mid) == true)
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
		// 원하는 갯수의 랜선이 안나오면 mid 이상은 절대 답이 될 수 없으므로 en = mid - 1
	}
	cout << st;

	return 0;
}