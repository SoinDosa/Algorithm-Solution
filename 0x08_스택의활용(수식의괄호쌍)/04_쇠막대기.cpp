// Authored by : BueVonHun
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/0e7137cb9b634cbcad7683ad783d432c
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string input;
	stack<char> st; // ���븦 ��� ����
	int result = 0;

	cin >> input;
	
	int size = input.length();
	
	for (int i = 0; i < size; ++i)
	{
		if (input[i] == '(')
		{
			st.push(input[i]);
		}
		else
		{
			if (input[i - 1] == '(') 
			{
				st.pop(); 
				// ����� �����ϰ� ���ÿ� �־����Ƿ� pop
				result += st.size(); 
				// ���� ������ �Ʒ��� �ִ� ����� ������ŭ ������ ����
			}
			// �������� ���
			else
			{
				st.pop();
				result++;
				// ������� ���� ��� ����Ⱑ �������Ͱ� �����Ƿ� 1 �߰�
			}
			// ������� ���� ���
		}
	}

	cout << result;

	return 0;
}