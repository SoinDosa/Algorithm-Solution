
// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// Commanded by : Soindosa
// http://boj.kr/9571e70535a34702812d2a03510ac182#include <iostream>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int M = 0;
	int result = 0;
	deque<int> dq;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		dq.push_back(i);
	}

	while (M--)
	{
		int number = 0;
		int idx = 0;
		int test = 0;
		cin >> number;
		idx = find(dq.begin(), dq.end(), number) - dq.begin();
		// number가 있는 인덱스
		// find 함수는 <algorithm> 헤더에 있음

		while (dq.front() != number)
		{
			if (idx < dq.size() - idx)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			// number가 있는 위치가 중간보다 앞일 경우 왼쪽으로 이동
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			// number가 있는 위치가 중간보다 뒤일 경우 오른쪽으로 이동
			result++;
			// 이동횟수 1 증가
		}

		dq.pop_front();
		// number를 찾았으니까 pop_front
	}

	cout << result;

	return 0;
}