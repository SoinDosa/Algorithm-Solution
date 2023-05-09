// Authored by : tongnamuu
// Co-authored by : -
// Commented by : Soindosa
#include <iostream>

using namespace std;

int prices[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> prices[i];
		}

		int maxVal = prices[N - 1];
		// �ڿ������� Ž���ϸ� �����´�
		unsigned long long result = 0;

		for (int i = N - 2; i >= 0; --i)
		{
			if (prices[i] > maxVal)
			{
				maxVal = prices[i];
			}
			// �ڿ������� ��ȸ�ϸ� �� ū���� �����ٸ� �ִ� ���ڸ� �����Ѵ�
			result += maxVal - prices[i];
		}
		
		cout << result << '\n';
	}

	return 0;
}