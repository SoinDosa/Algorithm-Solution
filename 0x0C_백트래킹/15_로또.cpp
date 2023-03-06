#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(true)
	{
		int k = 0;
		int S[15] = { 0, };
		int permutation[15] = { 0, };

		cin >> k;

		if (k == 0)
		{
			break;
		}

		for (int i = 0; i < k; ++i)
		{
			cin >> S[i];
			if (i >= 6)
			{
				permutation[i] = 1;
			}
		}
		sort(S, S + k);

		do
		{
			for (int i = 0; i < k; ++i)
			{
				if (permutation[i] == 0)
				{
					cout << S[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(permutation, permutation + k));

		cout << '\n';
		// 각 테스트 케이스는 개행으로 구분해야한다는 조건
	}

	return 0;
}