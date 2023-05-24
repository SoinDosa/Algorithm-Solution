// Authored by : scsc3204
// Commented by : Soindosa
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string names[1001];
vector<int> adj[1001];
unordered_map<string, int> people;
int indegree[1001];
vector<int> child[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> names[i];
	}
	sort(names + 1, names + 1 + N);
	// 이름을 사전순으로 출력하기 위함

	for (int i = 1; i <= N; ++i)
	{
		people[names[i]] = i;
	}

	int M;
	cin >> M;

	while (M--)
	{
		string u, v;
		cin >> u >> v;

		adj[people[v]].push_back(people[u]);
		indegree[people[u]]++;
	}

	vector<int> rt;
	for (int i = 1; i <= N; ++i)
	{
		if (indegree[i] == 0)
		{
			rt.push_back(i);
		}
	}
	// indegree가 0인 시조부터 시작

	cout << rt.size() << '\n';
	for (int idx : rt)
	{
		cout << names[idx] << ' ';
	}
	cout << '\n';

	for (int i = 1; i <= N; ++i)
	{
		sort(adj[i].begin(), adj[i].end());
		for (int c : adj[i])
		{
			if (indegree[c] - indegree[i] == 1)
			{
				child[i].push_back(c);
			}
		}
	}
	// indegree가 딱 1 차이나는 후손만 자식노드로 저장

	for (int i = 1; i <= N; ++i)
	{
		cout << names[i] << ' ' << child[i].size() << ' ';
		for (int ch : child[i])
		{
			cout << names[ch] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
