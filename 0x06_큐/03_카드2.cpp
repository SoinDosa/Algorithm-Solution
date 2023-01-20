#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	queue<int> q;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		if (q.size() == 1)
		{
			cout << q.front();
			break;
		}

		int frontNum = 0;

		q.pop();
		frontNum = q.front();
		q.pop();
		q.push(frontNum);
	}

	return 0;
}