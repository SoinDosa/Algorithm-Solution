#include <iostream>

using namespace std;

int main()
{
	int N = 0;
	int K = 0;
	int gender = 0;
	int year = 0;
	int students[2][6] = { 0, };
	int result = 0;
	
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> gender >> year;
		students[gender][year - 1]++;
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (students[i][j] % K == 0)
			{
				result += students[i][j] / K;
			}
			else
			{
				result += (students[i][j] / K + 1);
			}
		}
	}

	cout << result;

	return 0;
}