#include <iostream>

using namespace std;

int main()
{
	int a[3];

	while (true)
	{
		int max = 0;
		int maxIndex = 0;
		int result = 0;
		for (int i = 0; i < 3; ++i)
		{
			cin >> a[i];
			if (a[i] > max)
			{
				max = a[i];
				maxIndex = i;
			}
		}

		if (max == 0)
		{
			break;
		}

		for (int i = 0; i < 3; ++i)
		{
			if (i == maxIndex)
			{
				continue;
			}

			result += a[i] * a[i];
		}

		if (result == max * max)
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}
}