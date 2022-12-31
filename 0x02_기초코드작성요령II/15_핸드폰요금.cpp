#include <iostream>

using namespace std;

int N = 0;
int t[20] = { 0, };
int total = 0;

void calcTotal()
{
	int totalY = 0;
	int totalM = 0;

	for (int i = 0; i < N; ++i)
	{
		int y = (t[i] / 30) * 10 + 10;
		int m = (t[i] / 60) * 15 + 15;

		totalY += y;
		totalM += m;
	}

	if (totalY < totalM)
	{
		cout << "Y " << totalY;
	}
	else if (totalY > totalM)
	{
		cout << "M " << totalM;
	}
	else
	{
		cout << "Y M " << totalY;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> t[i];
	}

	calcTotal();

	return 0;
}