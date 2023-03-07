// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/b318d03bfd694a57be91322ff1dcd4ef
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool mask[25];
string board[5];
int cnt;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		cin >> board[i];
	}

	fill(mask + 7, mask + 25, true);
	// next_permutation 활용을 위해 mask[7]~mask[24]를 true로 채움

	do
	{
		queue<pair<int, int>> q;
		int s = 0;
		// 이다솜파의 수
		int adj = 0;
		// 가로세로로 인접한 사람의 수
		bool isPrincess7[5][5] = { };
		bool vis[5][5] = { };

		for (int i = 0; i < 25; ++i)
		{
			if (mask[i] == false)
			{
				int x = i / 5;
				int y = i % 5;

				isPrincess7[x][y] = true;
				if (q.empty())
				{
					q.push({ x, y });
					vis[x][y] = true;
				}
				// bfs 시작점이 필요하므로 최초 칠공주 후보 한 명의 위치를 큐에 넣는다
			}
		}
		// 총 7명의 칠공주 후보가 정해짐

		while (!q.empty())
		{
			pair<int, int> cur = q.front();

			q.pop();
			adj++;
			if (board[cur.first][cur.second] == 'S')
			{
				s++;
			}
			// 조건문을 연산자와 활용하는 방법
			for (int i = 0; i < 4; ++i)
			{
				int curX = cur.first + dx[i];
				int curY = cur.second + dy[i];

				if (curX < 0 || curX >= 5 || curY < 0 || curY >= 5)
				{
					continue;
				}

				if (vis[curX][curY] == true || isPrincess7[curX][curY] == false)
				{
					continue;
				}
				// 앞에서 정한 칠공주 후보가 아니라면 continue

				q.push({ curX, curY });
				vis[curX][curY] = true;
			}
		}
		// 가로세로 인접한지 bfs를 통해 확인

		if (adj >= 7 && s >= 4)
		{
			cnt++;
		}
		// 증가 조건
	} while (next_permutation(mask, mask + 25));

	cout << cnt;
}
/*
25명 중 칠공주가 배치될 수 있는 모든 조합을 시도합니다.
경우의 수가 많아보이지만, 25C7 = 480700이므로
충분히 2초안에 수행될 수 있습니다.
서로 가로세로로 인접해야 한다는 2번 조건은 여러가지 방법으로
확인할 수 있으나, 본 풀이에서는 BFS를 이용하였습니다.
*/