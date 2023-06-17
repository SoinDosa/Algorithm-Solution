#include <iostream>

using namespace std;

const int MAX_HAM = 3;
const int MAX_DRINK = 2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int hamburger[MAX_HAM] = {};
	int drink[MAX_DRINK] = {};

	for (int i = 0; i < MAX_HAM; ++i)
	{
		cin >> hamburger[i];
	}

	for (int i = 0; i < MAX_DRINK; ++i)
	{
		cin >> drink[i];
	}

	int cheapPrice = 0x7F7F7F7F;
	for (int i = 0; i < MAX_HAM; ++i)
	{
		for (int j = 0; j < MAX_DRINK; ++j)
		{
			cheapPrice = min(cheapPrice, hamburger[i] + drink[j] - 50);
		}
	}

	cout << cheapPrice;

	return 0;
}