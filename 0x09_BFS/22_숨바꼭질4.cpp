#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int subinPos, babyPos;
int dist[100001];
int prevPos[100001];
vector<int> path;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fill(dist, dist + 100001, -1);
	fill(prevPos, prevPos + 100001, -1);
	
	cin >> subinPos >> babyPos;

	if (subinPos == babyPos)
	{
		cout << 0 << '\n' << subinPos;
		return 0;
	}

	queue<int> q;

	dist[subinPos] = 0;
	q.push(subinPos);

	bool isFind = false;

	while (!isFind && !q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int nxt : { cur - 1, cur + 1, cur * 2 })
		{
			if (nxt < 0 || nxt > 100000)
			{
				continue;
			}

			if (dist[nxt] != -1)
			{
				continue;
			}

			if (nxt == babyPos)
			{
				dist[nxt] = dist[cur] + 1;
				prevPos[nxt] = cur;
				isFind = true;
				break;
			}

			prevPos[nxt] = cur;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	
	cout << dist[babyPos] << '\n';
	while (babyPos != -1)
	{
		path.push_back(babyPos);
		babyPos = prevPos[babyPos];
	}

	for (int i = path.size() - 1; i >= 0; --i)
	{
		cout << path[i] << ' ';
	}
	return 0;
}
