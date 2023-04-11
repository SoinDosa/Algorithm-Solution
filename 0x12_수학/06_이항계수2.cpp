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
		// iC0 = iCi = 1 , �Ѱ��� ����ۿ� ����
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 10007;
			// iCj = i-1Cj + i-1Cj-1 �̹Ƿ� DP�� ���� Ǯ �� �ִ�
		}
	}

	int N, K;
	// nCk�� ���ϱ�

	cin >> N >> K;
	cout << C[N][K];

	return 0;
}