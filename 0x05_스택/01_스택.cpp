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
			// if�� �������� �����ʿ� ���� stack.empty()�� ��������� 1��, �ƴϸ� 0�� ��ȯ
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
		// string �񱳽� compare vs operator==
		// ����� �ܰ迡���� ==�� �� ���� ������ ��ġ�� ������ �ܰ迡���� �����̰� ����
		// �뵵�� ���� ������ ����ϵ��� �Ѵ�
	}

	return 0;
}