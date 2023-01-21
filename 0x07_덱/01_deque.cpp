#include <iostream>
#include <deque>

using namespace std;

int main()
{
	int N = 0;
	deque<int> dq;

	cin >> N;
	while (N--)
	{
		string command;
		int input = 0;

		cin >> command;
		if (command == "push_front")
		{
			cin >> input;
			dq.push_front(input);
		}
		else if (command == "push_back")
		{
			cin >> input;
			dq.push_back(input);
		}
		else if (command == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << dq.empty() << '\n';
		}
		else if (command == "front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if (command == "back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}
	
	return 0;
}
