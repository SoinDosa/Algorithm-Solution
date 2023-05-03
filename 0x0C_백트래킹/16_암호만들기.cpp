#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
char characters[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> L >> C;
	for (int i = 0; i < C; ++i)
	{
		cin >> characters[i];
	}
	sort(characters, characters + C);

	vector<int> brute(C, 1);
	fill(brute.begin(), brute.begin() + L, 0);

	do {
		int consonant = 0;
		int vowel = 0;
		vector<char> result;

		for (int i = 0; i < C; ++i)
		{
			if (brute[i] == 0)
			{
				result.push_back(characters[i]);
				if (characters[i] == 'a' || characters[i] == 'e' || characters[i] == 'i' || characters[i] == 'o' || characters[i] == 'u')
				{
					vowel++;
				}
				else
				{
					consonant++;
				}
			}
		}

		if (consonant >= 2 && vowel >= 1)
		{
			for (char c : result)
			{
				cout << c;
			}
			cout << '\n';
		}
	} while (next_permutation(brute.begin(), brute.end()));

	return 0;
}