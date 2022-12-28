#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int minimum = 100;
	int sum = 0;
	bool isOdd = false;

	for (int i = 0; i < 7; ++i)
	{
		cin >> n;

		if (n & 1)
		// 홀수의 경우 1과 비트 AND 연산을 하면 1이 나오고 아니면 0이 나옴
		{
			isOdd = true;
			sum += n;

			if (n < minimum)
			{
				minimum = n;
			}
		}
	}

	if (isOdd)
	{
		cout << sum << '\n' << minimum;
	}
	else
	{
		cout << -1;
	}

	return 0;
}