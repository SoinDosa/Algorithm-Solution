// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/98a57090ad0b472f86492f495a362127
// Commented by : Soindosa
#include <iostream>
#include <stack>

using namespace std;

int input[1000000];
int result[1000000];
// �迭�� �������� �Ҵ�

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	stack<int> st;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}
	// ��� ������ �Է¹���

	for (int i = N - 1; i >= 0; --i)
	{
		while (!st.empty() && st.top() <= input[i])
		{
			st.pop();
		}

		if (st.empty())
		{
			result[i] = -1;
		}
		// �� �ڳ� ���� ū ���� ��ū���� �����ϱ� -1�� ��
		else
		{
			result[i] = st.top();
		}
		// i ��° ������ push�ϱ� ���� ��ū���� �Ҵ�

		st.push(input[i]);
	}
	// �ڿ������� ��ȸ

	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << ' ';
	}

	return 0;
}