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
				// Pk = PN�ϰ�� k�� 1 ���ҽ�Ű�� result ����
				i += 2;
				// i�� 2�� �����ϸ� OI �ϳ��� üũ
			}
			k = 0;
		}
		// I�� ������ OI�� ���ö����� k ����
	}

	cout << result;

	return 0;
}
// string.find�� ����ϸ� 50��