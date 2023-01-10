#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> st;
	int N = 0;
	string op;
	int X = 0;

	cin >> N;
	while (N--)
	{
		cin >> op;
		if (op == "push")
		{
			cin >> X;
			st.push(X);
		}
		else if (op == "pop")
		{
			if (st.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (op == "size")
		{
			cout << st.size() << '\n';
		}
		else if (op == "empty") 
		{
			cout << st.empty() << '\n';
			// if문 조건으로 나눌필요 없이 stack.empty()는 비어있으면 1을, 아니면 0을 반환
		}
		else if (op == "top")
		{
			if (st.empty())
			{
				cout << -1 << '\n';;
			}
			else
			{
				cout << st.top() << '\n';
			}
		}
		// string 비교시 compare vs operator==
		// 디버그 단계에서는 ==가 더 많은 과정을 거치나 릴리즈 단계에서는 별차이가 없다
		// 용도에 따라 적절히 사용하도록 한다
	}

	return 0;
}