#include <iostream>
#include <algorithm>

using namespace std;

string arr[51];

bool cmp(const string& a, const string& b)
{
	if (a.length() == b.length())
	{
		int aSize = 0;
		int bSize = 0;

		for (char aChar : a)
		{
			if (aChar >= '0' && aChar <= '9')
			{
				aSize += aChar - '0';
			}
		}

		for (char bChar : b)
		{
			if (bChar >= '0' && bChar <= '9')
			{
				bSize += bChar - '0';
			}
		}
		// a, b Size에 char을 그대로 더하면 틀리고 '0'을 빼줘야 정답처리됨

		if (aSize == bSize)
		{
			return a < b;
		}

		return aSize < bSize;
	}

	return a.length() < b.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N, cmp);

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}