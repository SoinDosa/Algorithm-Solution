#include <iostream>
using namespace std;

int N, K;
int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	int st = 0;
	int en = 0;
	int maxLen = 0;
	int len = 0;
	int eraseCnt = 0;
	while (st < N && en < N)
	{
		while (en < N)
		{
			if (arr[en] % 2 == 1)
			{
				if (eraseCnt == K)
				{
					break;
				}

				if (len != 0)
				{
					eraseCnt++;
				}
				else
				{
					st = en + 1;
				}
			}
			else
			{
				len++;
			}
			++en;
		}

		maxLen = max(maxLen, len);

		while (eraseCnt == K)
		{
			if (arr[st] % 2 == 1)
			{
				eraseCnt--;
			}
			else
			{
				len--;
			}
			++st;
		}
	}
	cout << maxLen;
}
