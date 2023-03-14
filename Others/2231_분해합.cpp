#include <iostream>

using namespace std;

bool isConstructor(int n, int sum)
{
	int tmp = n;
	
	while (n != 0)
	{
		tmp += n % 10;
		n /= 10;
	}

	if (tmp == sum)
	{
		return true;
	}
	
	return false;
}

int disCountDigit(int n)
{
	int tmp = n;

	while (n != 0)
	{
		tmp -= 9;
		n /= 10;
	}

	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int minNum = 0;
	
	cin >> N;
	minNum = disCountDigit(N);

	while (minNum <= N)
	{
		if (isConstructor(minNum, N) == true)
		{
			cout << minNum;

			return 0;
		}
		minNum++;
	}
	cout << 0;

	return 0;
}