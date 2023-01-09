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
					// it가 가리키는 값을 제거하고 그 다음 원소의 위치를 반환
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