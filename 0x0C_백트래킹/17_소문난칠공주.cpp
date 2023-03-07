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
	// next_permutation Ȱ���� ���� mask[7]~mask[24]�� true�� ä��

	do
	{
		queue<pair<int, int>> q;
		int s = 0;
		// �̴ټ����� ��
		int adj = 0;
		// ���μ��η� ������ ����� ��
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
				// bfs �������� �ʿ��ϹǷ� ���� ĥ���� �ĺ� �� ���� ��ġ�� ť�� �ִ´�
			}
		}
		// �� 7���� ĥ���� �ĺ��� ������

		while (!q.empty())
		{
			pair<int, int> cur = q.front();

			q.pop();
			adj++;
			if (board[cur.first][cur.second] == 'S')
			{
				s++;
			}
			// ���ǹ��� �����ڿ� Ȱ���ϴ� ���
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
				// �տ��� ���� ĥ���� �ĺ��� �ƴ϶�� continue

				q.push({ curX, curY });
				vis[curX][curY] = true;
			}
		}
		// ���μ��� �������� bfs�� ���� Ȯ��

		if (adj >= 7 && s >= 4)
		{
			cnt++;
		}
		// ���� ����
	} while (next_permutation(mask, mask + 25));

	cout << cnt;
}
/*
25�� �� ĥ���ְ� ��ġ�� �� �ִ� ��� ������ �õ��մϴ�.
����� ���� ���ƺ�������, 25C7 = 480700�̹Ƿ�
����� 2�ʾȿ� ����� �� �ֽ��ϴ�.
���� ���μ��η� �����ؾ� �Ѵٴ� 2�� ������ �������� �������
Ȯ���� �� ������, �� Ǯ�̿����� BFS�� �̿��Ͽ����ϴ�.
*/