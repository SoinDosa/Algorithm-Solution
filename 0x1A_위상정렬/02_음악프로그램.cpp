#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[1001];
int indegree[1001];
vector<int> result;

void topological_sort()
{
	queue<int> q;
	
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		result.push_back(cur);

		for (int nxt : adj[cur])
		{
			indegree[nxt]--;
			if (indegree[nxt] == 0)
			{
				q.push(nxt);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	while (M--)
	{
		int cnt;
		cin >> cnt;

		int prevNum = 0;
		for (int i = 0; i < cnt; ++i)
		{
			int singerNum;
			cin >> singerNum;

			if (i > 0)
			{
				adj[prevNum].push_back(singerNum);
				indegree[singerNum]++;
			}

			prevNum = singerNum;
		}
	}

	topological_sort();

	if (result.size() != N)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << result[i] << '\n';
	}

	return 0;
}