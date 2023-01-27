// Authored by : std-freejia
// Co-authored by : BaaaaaaaaaaarkingDog, rhsnfl1122
// Commented by : Soindosa
// http://boj.kr/cbef82389d1048db80c9652d18b71304
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	stack<char> st;
	int sum = 0;
	// ���� ��� ��
	int num = 1;
	// ������ ��

	cin >> input;
	int inputSize = input.length();
	for (int i = 0; i < inputSize; ++i)
	{
		if (input[i] == '(')
		{
			num *= 2;
			// �Ұ�ȣ�� ������ ������ �� 2�� ����
			st.push(input[i]);
		}
		else if (input[i] == '[')
		{
			num *= 3;
			// ���ȣ�� ������ ������ �� 3�� ����
			st.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << '0';
				return 0;
			}
			// �߸��� ��ȣ ó��
			
			if (input[i - 1] == '(')
			{
				sum += num;
				// ��ȣ ���� ������ �� ���Ѵ�
			}
			st.pop();
			num /= 2;
			// �Ұ�ȣ ���� ��������� ���� ���� 2�� ����
		}
		else if (input[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << '0';
				return 0;
			}
			// �߸��� ��ȣ ó��

			if (input[i - 1] == '[')
			{
				sum += num;
			}
			st.pop();
			num /= 3;
			// ���ȣ ���� ��������� ���� ���� 3���� ����
		}
	}

	if (st.empty())
	{
		cout << sum;
	}
	else
	{
		cout << 0;
	}

	return 0;
}
/*
boj 10799 �� ����� ������ ���̵��� ����ϰ� �پ��ִ� () Ȥ�� []�� ������
sum�� ������ ������. () Ȥ�� []�� �� ���ΰ��� ��ø�� �Ұ�ȣ/���ȣ�� ������
��� �����ϰ� �̴� ���� num�� ������ ��. 
*/
// ��ȣ�� �ϳ��� Ǯ�� �����ϱ� ����
// ���� - (2) * (2) + (2) * [3] * [3] + (2) * [3]