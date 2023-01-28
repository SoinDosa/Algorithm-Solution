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
	// 최종 결과 값
	int num = 1;
	// 곱해질 값

	cin >> input;
	int inputSize = input.length();
	for (int i = 0; i < inputSize; ++i)
	{
		if (input[i] == '(')
		{
			num *= 2;
			// 소괄호가 나오면 곱해질 값 2배 증가
			st.push(input[i]);
		}
		else if (input[i] == '[')
		{
			num *= 3;
			// 대괄호가 나오면 곱해질 값 3배 증가
			st.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (st.empty() || st.top() != '(')
			{
				cout << '0';
				return 0;
			}
			// 잘못된 괄호 처리
			
			if (input[i - 1] == '(')
			{
				sum += num;
				// 괄호 안의 점수는 다 더한다
			}
			st.pop();
			num /= 2;
			// 소괄호 쌍이 사라졌으니 곱할 값을 2로 나눔
		}
		else if (input[i] == ']')
		{
			if (st.empty() || st.top() != '[')
			{
				cout << '0';
				return 0;
			}
			// 잘못된 괄호 처리

			if (input[i - 1] == '[')
			{
				sum += num;
			}
			st.pop();
			num /= 3;
			// 대괄호 쌍이 사라졌으니 곱할 값을 3으로 나눔
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
boj 10799 쇠 막대기 문제의 아이디어와 비슷하게 붙어있는 () 혹은 []를 만나면
sum에 점수를 더해줌. () 혹은 []이 몇 점인가는 중첩된 소괄호/대괄호의 곱으로
계산 가능하고 이는 변수 num에 저장이 됨. 
*/
// 괄호를 하나씩 풀면 이해하기 쉬움
// 예제 - (2) * (2) + (2) * [3] * [3] + (2) * [3]