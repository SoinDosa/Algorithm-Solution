#include <iostream>

using namespace std;

int main()
{
	string a = "";
	string b = "";
	int charSet[26] = { 0, };
	int result = 0;

	cin >> a >> b;
	for (char c : a)
	{
		charSet[c - 'a']++;
	}
	for (char c : b)
	{
		charSet[c - 'a']--;
	}

	for (int i : charSet)
	{
		result += abs(i);
	}
	cout << result;

	return 0;
}