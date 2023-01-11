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
			// ���ڸ� push�ϰ� ���ÿ� +1 �ϱ�, �� �ٿ� ���� �� �ִ� ���
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