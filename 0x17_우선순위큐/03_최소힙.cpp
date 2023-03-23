#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;
	int N = 0;

	cin >> N;
	while (N--)
	{
		int input = 0;

		cin >> input;

		if (input == 0)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else if (input != 0)
		{
			pq.push(input);
		}
	}

	return 0;
}