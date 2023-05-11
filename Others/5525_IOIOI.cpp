#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	string S;
	cin >> N >> M >> S;

	int result = 0;
	for (int i = 0; i < M; ++i)
	{
		int k = 0;

		if (S[i] == 'O')
		{
			continue;
		}
		else
		{
			while (S[i + 1] == 'O' && S[i + 2] == 'I')
			{
				k++;
				if (k == N)
				{
					k--;
					result++;
				}
				// Pk = PN일경우 k를 1 감소시키고 result 증가
				i += 2;
				// i를 2씩 증가하며 OI 하나씩 체크
			}
			k = 0;
		}
		// I가 나오면 OI가 나올때마다 k 증가
	}

	cout << result;

	return 0;
}
// string.find를 사용하면 50점