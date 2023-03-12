#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	while (N--)
	{
		int input = 0;

		cin >> input;
		pq.push(input);
	}

	int result = 0;

	while (pq.size() > 1)
	{
		int a = pq.top();

		pq.pop();

		int b = pq.top();

		pq.pop();

		result += a + b;
		pq.push(a + b);
	}

	cout << result;

	return 0;
}