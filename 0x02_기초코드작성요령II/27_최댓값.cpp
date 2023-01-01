#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int maximum = 0;
	int maxIndex = 0;

	for (int i = 0; i < 9; ++i)
	{
		cin >> n;
		if (n > maximum)
		{
			maximum = n;
			maxIndex = i + 1;
		}
	}

	cout << maximum << '\n' << maxIndex;

	return 0;
	// max_element를 이용한 풀이도 알아보자
}