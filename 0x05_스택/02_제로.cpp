#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int K = 0;
	int input = 0;
	stack<int> money;
	int result = 0;

	cin >> K;
	while (K--)
	{
		cin >> input;
		if (input == 0)
		{
			money.pop();
		}
		else
		{
			money.push(input);
		}
	}

	while (!money.empty())
	{
		result += money.top();
		money.pop();
	}
	cout << result;

	return 0;
}