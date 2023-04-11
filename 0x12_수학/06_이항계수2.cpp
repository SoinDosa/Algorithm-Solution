#include <iostream>

using namespace std;

int C[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i <= 1000; ++i)
	{
		C[i][0] = C[i][i] = 1;
		// iC0 = iCi = 1 , 한가지 방법밖에 없다
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
			// iCj = i-1Cj + i-1Cj-1 이므로 DP를 통해 풀 수 있다
		}
	}

	int N, K;
	// nCk를 구하기

	cin >> N >> K;
	cout << C[N][K];

	return 0;
}