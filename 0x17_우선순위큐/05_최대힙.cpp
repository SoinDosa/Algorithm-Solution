#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	
	cin >> N;
	while (N--)
	{
		int x;

		cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}