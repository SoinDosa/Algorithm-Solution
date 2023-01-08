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
	// auto로 선언하면 편리하지만 정확한 사용법도 숙지

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
				// 커서 왼쪽에 있는걸 삭제해야하지만 실수로 커서 위치에 있는걸 삭제하게 해서 틀림
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