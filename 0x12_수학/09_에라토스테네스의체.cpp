#include <iostream>

using namespace std;

bool isRemoved[1001];

int main()
{
	int N, K;
	int cnt = 0;
	cin >> N >> K;

	for (int i = 2; i <= N; ++i)
	{
		if (isRemoved[i])
		{
			continue;
		}

		isRemoved[i] = true;
		cnt++;
		if (cnt == K)
		{
			cout << i;
			return 0;
		}

		int temp = i + i;
		while (temp <= N)
		{
			if (isRemoved[temp])
			{
				temp += i;
				continue;
			}

			isRemoved[temp] = true;
			cnt++;

			if (cnt == K)
			{
				cout << temp;
				return 0;
			}

			temp += i;
		}
	}
	
	return 0;
}