#include <iostream>
using namespace std;

char moo[3] = { 'm', 'o', 'o' };

void func(int n, int k, int len)
{
	if (n <= 3)
	{
		cout << moo[n - 1];
		return;
	}
	// n이 3이하가 되면 moo에 맞게 출력

	int newLen = 2 * len + k + 3;
	// S(k + 1)의 길이

	if (newLen < n)
	{
		func(n, k + 1, newLen);
	}
	// 찾으려는 위치인 n보다 작으면 한 번 더 수행
	else
	{
		if (n > len && n <= len + k + 3)
		{
			if (n - len != 1)
			{
				cout << 'o';
			}
			else
			{
				cout << 'm';
			}
			return;
		}
		// 가운데에 있는 문자열(연속된 o)이라면 맞게 출력
		else
		{
			func(n - (len + k + 3), 1, 3);
		}
		// 그 외라면 n을 S(k)만큼 빼고 다시 처음부터 탐색
	}
}

int main()
{
	long long N;
	cin >> N;

	func(N, 1, 3);
	// 첫 시작은 k = 1, 길이는 3

	return 0;
}