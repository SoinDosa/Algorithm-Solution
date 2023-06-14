#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while (N--)
	{
		string input;
		cin >> input;

		for (char c : input)
		{
			if (c < 'a')
			{
				c += 32;
			}
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}