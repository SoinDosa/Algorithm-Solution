#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isRoute[101][101];
vector<int> adj[101];

void bfs(int st)
{
	bool isVis[101] = {};
	queue<int> q;

	q.push(st);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : adj[cur])
		{
			if (isVis[nxt] == true)
			{
				continue;
			}

			isRoute[st][nxt] = true;
			isVis[nxt] = true;
			// isVis를 여기서만 갱신해야 st -> st 경로를 체크할 수 있다
			q.push(nxt);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int input;
			cin >> input;

			if (input == 0)
			{
				continue;
			}
			
			adj[i].push_back(j);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		bfs(i);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << isRoute[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
