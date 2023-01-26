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
	stack<char> st; // 막대를 담는 스택
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
				// 막대로 착각하고 스택에 넣었으므로 pop
				result += st.size(); 
				// 현재 레이저 아래에 있는 막대기 갯수만큼 조각이 생김
			}
			// 레이저일 경우
			else
			{
				st.pop();
				result++;
				// 막대기의 끝일 경우 막대기가 조각난것과 같으므로 1 추가
			}
			// 막대기의 끝인 경우
		}
	}

	cout << result;

	return 0;
}