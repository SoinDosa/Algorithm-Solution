#include <iostream>

using namespace std;

int main()
{
	int eng[26] = { 0, };
	string S;

	cin >> S;
	for (char s : S)
	{
		eng[s - 97]++;
	}

	for (int engCount : eng)
	{
		cout << engCount << ' ';
	}

	return 0;
}