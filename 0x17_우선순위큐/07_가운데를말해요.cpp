#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> minPQ;
priority_queue<int> maxPQ;
int N;

void swapMinMax()
{
	minPQ.push(maxPQ.top());
	maxPQ.push(minPQ.top());
	maxPQ.pop();
	minPQ.pop();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int num;
		cin >> num;

		if (maxPQ.size() <= minPQ.size())
		{
			maxPQ.push(num);
		}
		else
		{
			minPQ.push(num);
		}

		if (!minPQ.empty() && maxPQ.top() > minPQ.top())
		{
			swapMinMax();
		}
		cout << maxPQ.top() << '\n';
	}
}
// ios, cin.tie 처리 안해주면 시간초과;;
