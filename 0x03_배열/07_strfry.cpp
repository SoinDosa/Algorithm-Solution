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
		// charSet�� �ϳ��� �ּ� a������ ++, b������ -- ������ ��
		// charSet[i] != 0 ���� �Ǵ��ϴ� ����� ����
		// ���� ���⵵ ���� ����

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