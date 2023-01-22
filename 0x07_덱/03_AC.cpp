#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int n = 0;
		int tmp = 0;
		bool isValid = true;
		bool isFront = true;
		string p;
		string arr;
		deque<int> dq;

		cin >> p >> n >> arr;
		for (char c : arr)
		{
			if (c == '[')
			{
				continue;
			}
			else if (c == ',' || c == ']')
			{
				if (tmp != 0)
				{
					dq.push_back(tmp);
					tmp = 0;
				}
			}
			else
			{
				tmp *= 10;
				tmp += c - '0';
			}
		}

		for (char c : p)
		{
			if (c == 'R')
			{
				isFront = !isFront;
			}
			else if (c == 'D')
			{
				if (dq.empty())
				{
					isValid = false;
					break;
				}
				else
				{
					if (isFront)
					{
						dq.pop_front();
					}
					else
					{
						dq.pop_back();
					}
				}
			}
		}

		if (!isValid)
		{
			cout << "error\n";
		}
		else
		{
			cout << '[';
			while (!dq.empty())
			{
				if (isFront)
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
					{
						cout << ',';
					}
				}
				else
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
					{
						cout << ',';
					}
				}
			}
			cout << ']' << '\n';
		}
	}

	return 0;
}