#include <iostream>
#include <deque>

using namespace std;

bool isFront(deque<pair<int, int>>& d, pair<int, int> cur)
{
	for (pair<int, int> now : d)
	{
		if (now.second > cur.second)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;
	
	cin >> T;
	while (T--)
	{
		deque<pair<int, int>> d;

		int N = 0;
		int M = 0;
		int cnt = 0;
		bool isComplete = false;

		cin >> N >> M;

		for (int i = 0; i < N; ++i)
		{
			int priority = 0;

			cin >> priority;
			d.push_back({ i, priority });
		}

		while (!d.empty() && isComplete == false)
		{
			pair<int, int> cur = d.front();

			if (isFront(d, cur))
			{
				cnt++;
				if (cur.first == M)
				{
					cout << cnt << '\n';
					isComplete = true;
					break;
				}
				d.pop_front();
			}
			else
			{
				d.push_back(cur);
				d.pop_front();
			}
		}
	}

	return 0;
}