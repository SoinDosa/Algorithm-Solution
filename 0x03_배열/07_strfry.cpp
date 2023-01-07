#include <iostream>

using namespace std;

int main()
{
	int N;
	string a = "";
	string b = "";

	cin >> N;
	while (N--)
	{
		int charSetA[26] = { 0, };
		int charSetB[26] = { 0, };
		bool isPossible = true;

		cin >> a >> b;
		for (char c : a)
		{
			charSetA[c - 'a']++;
		}
		for (char c : b)
		{
			charSetB[c - 'a']++;
		}
		// charSet을 하나만 둬서 a에서는 ++, b에서는 -- 연산한 후
		// charSet[i] != 0 임을 판단하는 방법이 있음
		// 공간 복잡도 절약 가능

		for (int i = 0; i < 26; ++i)
		{
			if (charSetA[i] != charSetB[i])
			{
				cout << "Impossible" << '\n';
				isPossible = false;
				break;
			}
		}

		if (isPossible)
		{
			cout << "Possible" << '\n';
		}
	}

	return 0;
}