#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	while (true)
	{
		long long L, P, V;
		long long result;

		cin >> L >> P >> V;
		t++;
		if (L == 0 && P == 0 && V == 0)
		{
			return 0;
		}

		result = L * (V / P) + min(V % P, L);
		// 오답정리 : min(V % P, L) 인 이유
		// V % P가 L보다 큰 경우가 있음, 이러면 틀린다

		cout << "Case " << t << ": " << result << '\n';
	}

	return 0;
}