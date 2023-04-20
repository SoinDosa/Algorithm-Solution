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
		// �������� : min(V % P, L) �� ����
		// V % P�� L���� ū ��찡 ����, �̷��� Ʋ����

		cout << "Case " << t << ": " << result << '\n';
	}

	return 0;
}