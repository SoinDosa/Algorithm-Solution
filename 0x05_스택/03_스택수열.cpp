#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	stack<int> st;
	string result;
	int pushNumber = 1;
	int seq = 0;

	cin >> n;
	while (n--)
	{
		cin >> seq;
		while (pushNumber <= seq)
		{
			st.push(pushNumber++);
			// 숫자를 push하고 동시에 +1 하기, 한 줄에 넣을 수 있는 방법
			result += "+\n";
		}

		if (st.top() != seq)
		{
			cout << "NO\n";
			return 0;
		}

		st.pop();
		result += "-\n";
	}

	cout << result;

	return 0;
}