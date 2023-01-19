// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/d98aedfde0e444509de83f1a21c8ef7e
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int n = 0;

		cin >> n;
		if (n == 0)
		{
			break;
		}

		stack <pair<long long, int>> st;
		// 히스토그램의 <높이, 인덱스>를 저장하는 스택
		long long result = 0;
		// height의 최대가 10억이므로 당연히 long long

		for (int i = 0; i < n; ++i)
		{
			long long h = 0;
			int index = i;
			// 현재 입력받는 인덱스

			cin >> h;
			while (!st.empty() && st.top().first >= h)
			{
				result = max(result, (i - st.top().second) * st.top().first);
				index = st.top().second;
				// 인덱스를 바꾸고 넣음으로써 해당 높이가 어느 너비까지
				// 반영가능한지 파악함
				// ex) {1, 0}이 스택에 들어가면 높이 1은 0번 인덱스까지 가능하다는 뜻
				st.pop();
			}
			// st에서 가장 컸던 높이의 너비를 1로 한 다음
			// 그 다음으로 큰 높이의 직사각형 너비를 1더해가며 result 갱신
			st.push({ h, index });
		}

		while (!st.empty())
		{
			result = max(result, (n - st.top().second) * st.top().first);
			st.pop();
		}
		// 마지막 입력된 높이까지 반영하여 최대 너비 파악

		cout << result << '\n';
	}
	// 0을 입력받기 전까지 무한루프

	return 0;
}