#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n = 0;
	string input;

	cin >> n;
	while (n--)
	{
		list<char> password;
		auto it = password.begin();

		cin >> input;
		for (char c : input)
		{
			switch (c)
			{
			case '<':
				if (it != password.begin())
				{
					it--;
				}
				break;
			case '>':
				if (it != password.end())
				{
					it++;
				}
				break;
			case '-':
				if (it != password.begin())
				{
					it--;
					it = password.erase(it);
					// it�� ����Ű�� ���� �����ϰ� �� ���� ������ ��ġ�� ��ȯ
				}
				break;
			default :
				password.insert(it, c);
				break;
			}
		}

		for (char c : password)
		{
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}