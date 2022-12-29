#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int numbers[9] = { 0, };
	int result[7] = { 0, };

	for (int i = 0; i < 9; ++i)
	{
		cin >> numbers[i];
	}

	for (int a = 0; a < 8; ++a)
	{
		int sum = 0;

		for (int b = a + 1; b < 9; ++b)
		{
			sum = 0;

			for (int c = 0, i = 0; c < 9; ++c)
			{
				if (c != a && c != b)
				{
					result[i++] = numbers[c];
					// 반복문에서 두 가지 변수를 활용하기
				}
			}

			for (int i = 0; i < 7; ++i)
			{
				sum += result[i];
			}

			if (sum == 100)
			{
				break;
			}
		}
		
		if (sum == 100)
		{
			break;
		}
	}

	sort(result, result + 7);
	
	for (int i = 0; i < 7; ++i)
	{
		cout << result[i] << '\n';
	}

	return 0;
}