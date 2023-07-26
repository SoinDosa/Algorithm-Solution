#include <iostream>
using namespace std;

bool isUsed[10];
char signs[11];
int arr[11];
int n;
long long maxNum = 0;
long long minNum = 0x7FFFFFFFFFFFFFFF;
// longlong이니까 최댓값을 매우 크게 설정
int maxNumArr[11];
int minNumArr[11];

void func(int cur)
{
	if (cur == n + 1)
	{
		long long num = 0;
		for (int i = 0; i < n + 1; ++i)
		{
			num *= 10;
			num += arr[i];
		}
		
		if (num > maxNum)
		{
			maxNum = num;
			for (int i = 0; i < n + 1; ++i)
			{
				maxNumArr[i] = arr[i];
			}
		}

		if (num < minNum)
		{
			minNum = num;
			for (int i = 0; i < n + 1; ++i)
			{
				minNumArr[i] = arr[i];
			}
		}

		return;
	}

	for (int i = 0; i <= 9; ++i)
	{
		if (!isUsed[i])
		{
			if (cur == 0)
			{
				isUsed[i] = true;
				arr[cur] = i;
				func(cur + 1);
				isUsed[i] = false;
			}
			else
			{
				if (signs[cur - 1] == '>' && arr[cur - 1] > i)
				{
					isUsed[i] = true;
					arr[cur] = i;
					func(cur + 1);
					isUsed[i] = false;
				}
				else if (signs[cur - 1] == '<' && arr[cur - 1] < i)
				{
					isUsed[i] = true;
					arr[cur] = i;
					func(cur + 1);
					isUsed[i] = false;
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> signs[i];
	}

	func(0);

	for (int i = 0; i < n + 1; ++i)
	{
		cout << maxNumArr[i];
	}
	cout << '\n';
	for (int i = 0; i < n + 1; ++i)
	{
		cout << minNumArr[i];
	}

}