#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(const int& a, const int& b)
	{
		if (abs(a) != abs(b))
		{
			return abs(a) > abs(b);
		}

		return a > 0 && b < 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, cmp> pq;

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
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(input);
		}
	}

	return 0;
}