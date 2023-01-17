// Authored by : haneulkimdev
// Co-authored by : -
// Commented by : Soindosa
// http://boj.kr/cbef82389d1048db80c9652d18b71304
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	stack<pair<int, int>> st;
	// first는 사람의 키, second는 같은 키를 가진 사람의 갯수
	long long result = 0;
	// long long인 이유 : N번째 사람이 500000 - N 가지 쌍을 가지는 경우
	// 499999 + 499998 + ... + 2 + 1 = 500000 * 250000 = 1250억

	cin >> N;
	while (N--)
	{
		int height;
		int count = 1;

		cin >> height;
		// height는 현재 사람의 키, st은 내 앞에 있는 사람을 의미
		while (!st.empty() && st.top().first <= height)
		{
			result += st.top().second;
			if (st.top().first == height)
			{
				count += st.top().second;
			}
			// 키가 같을 경우 해당 키를 가진 사람의 count를 늘린다
			st.pop();
		}
		// 현재 사람의 키보다 작은 사람들은 pop하고 인원수만큼 result를 늘린다
		// 사이에 낀 키가 작은 사람은 이 과정에서 자연스럽게 st에서 빠진다

		if (!st.empty())
		{
			result++;
		}
		// st이 비어있지 않다 == 현재 사람이 st 최상단에 있는 사람 한명만 볼 수 있다
		
		st.push({ height, count });
	}

	cout << result;

	return 0;
}