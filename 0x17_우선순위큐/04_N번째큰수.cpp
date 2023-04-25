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
	// ���� ���� ���ҵ鸸 ����鼭 ���� N���� ���� ����

	cout << pq.top();
	// ���� N���� ���� �������Ƿ� ���� ���� ���� N��°�� ū ��

	return 0;
}