#include <iostream>

using namespace std;

int A[100001];
int minResult = 0x7FFFFFFF;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, S;

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	int en = 0;
	int tot = A[0];
	for (int st = 0; st < N; ++st)
	{
		while (en < N && tot < S)
		{
			en++;
			if (en != N)
			{
				tot += A[en];
			}
		}
		if (en == N)
		{
			break;
		}
		minResult = min(minResult, en - st + 1);
		tot -= A[st];
	}
	if (minResult == 0x7FFFFFFF)
	{
		minResult = 0;
	}
	cout << minResult;

	return 0;
}