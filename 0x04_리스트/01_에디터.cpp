#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<char> charList;
	char c = 0;
	int N = 0;
	char command;
	char ch;

	while (1)
	{
		c = cin.get();
		if (c == '\n')
		{
			break;
		}
		charList.push_back(c);
	}
	list<char>::iterator cursor = charList.end();
	// auto�� �����ϸ� �������� ��Ȯ�� ������ ����

	cin >> N;
	while (N--)
	{
		cin >> command;
		switch (command)
		{
			case 'L':
				if (cursor != charList.begin())
				{
					cursor--;
				}
				break;
			case 'D':
				if (cursor != charList.end())
				{
					cursor++;
				}
				break;
			case 'B':
				if (cursor != charList.begin())
				{
					cursor--;
					cursor = charList.erase(cursor);
				}
				// Ŀ�� ���ʿ� �ִ°� �����ؾ������� �Ǽ��� Ŀ�� ��ġ�� �ִ°� �����ϰ� �ؼ� Ʋ��
				break;
			case 'P':
				cin >> ch;
				charList.insert(cursor, ch);
				break;
			default:
				break;
		}
	}

	for (char c : charList)
	{
		cout << c;
	}

	return 0;
}