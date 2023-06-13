#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int cnt = 0;
		string input;
		getline(cin, input);

		if (input == "#")
		{
			break;
		}

		for (char c : input)
		{
			if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
			{
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}