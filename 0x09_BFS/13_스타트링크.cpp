#include <iostream>
#include <queue>

using namespace std;

int cnt[1000001];
int F, S, G, U, D;

bool oob(const int& cur)
{
	return (cur < 1 || cur > F);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> F >> S >> G >> U >> D;
	fill(cnt, cnt + F + 1, -1);
	
	queue<int> q;

	cnt[S] = 0;
	q.push(S);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int e : { U, -D })
		{
			int nxt = cur + e;

			if (oob(nxt))
			{
				continue;
			}

			if (cnt[nxt] != -1)
			{
				continue;
			}

			cnt[nxt] = cnt[cur] + 1;
			q.push(nxt);
		}
	}

	if (cnt[G] == -1)
	{
		cout << "use the stairs";
	}
	else
	{
		cout << cnt[G];
	}

	return 0;
}