// Authored by : haneulkimdev
// Co-authored by : -
// http://boj.kr/98a57090ad0b472f86492f495a362127
// Commented by : Soindosa
#include <iostream>
#include <stack>

using namespace std;

int input[1000000];
int result[1000000];
// 배열은 힙공간에 할당

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
	// 모든 순열을 입력받음

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
		// 맨 뒤나 가장 큰 수는 오큰수가 없으니까 -1이 들어감
		else
		{
			result[i] = st.top();
		}
		// i 번째 순열을 push하기 전에 오큰수를 할당

		st.push(input[i]);
	}
	// 뒤에서부터 순회

	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << ' ';
	}

	return 0;
}