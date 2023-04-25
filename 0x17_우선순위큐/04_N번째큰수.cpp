#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	
	priority_queue<int, vector<int>, greater<>> pq;

	for (int i = 0; i < N * N; ++i)
	{
		int num;
		cin >> num;

		pq.push(num);
		if (pq.size() > N)
		{
			pq.pop();
		}
	}
	// 가장 작은 원소들만 지우면서 상위 N개의 값만 저장

	cout << pq.top();
	// 상위 N개의 값만 남겼으므로 가장 작은 수가 N번째로 큰 수

	return 0;
}