// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/c6dff411258544ce8393f745f463df33
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M;
pair<int, int> red, blue;
// ���� ������ �Ķ� ������ ��ġ
string board[11];
int dist[11][11][11][11];
// dist[a][b][c][d] ���� ������ a, b�̰� �Ķ� ������ c,d�� ��ġ�� ��Ȳ�� �����ϱ� ���� ������ Ƚ��

int bfs()
{
	queue<tuple<int, int, int, int>> q;
	q.push({ red.first, red.second, blue.first, blue.second });
	dist[red.first][red.second][blue.first][blue.second] = 0;
	// ���� �۾�

	while (!q.empty())
	{
		int rx = 0, ry = 0, bx = 0, by = 0;
		tie(rx, ry, bx, by) = q.front();
		q.pop();

		int cnt = dist[rx][ry][bx][by];

		if (cnt >= 10)
		{
			return -1;
		}
		// 10�� �Ѱ� ������ ������ Ż�� ���ϸ� -1;

		for (int dir = 0; dir < 4; ++dir)
		{
			int curRX = rx;
			int curRY = ry;
			int curBX = bx;
			int curBY = by;

			while (board[curBX + dx[dir]][curBY + dy[dir]] == '.')
			{
				curBX += dx[dir];
				curBY += dy[dir];
			}
			// �Ķ� �� �̵�, �̵��� ĭ�� '.'�̶�� ��� ���⸸ŭ �̵���Ų��
			if (board[curBX + dx[dir]][curBY + dy[dir]] == 'O')
			{
				continue;
			}
			// �Ķ� ���� Ż���ߴٸ� ����, continue

			while (board[curRX + dx[dir]][curRY + dy[dir]] == '.')
			{
				curRX += dx[dir];
				curRY += dy[dir];
			}
			// ���� �� �̵�
			if (board[curRX + dx[dir]][curRY + dy[dir]] == 'O')
			{
				return cnt + 1;
			}
			// ���� ���� Ż���ߴٸ� ����, �ٷ� ���� ��ȯ

			if (curRX == curBX && curRY == curBY)
			{
				switch (dir)
				{
				case 0:
					ry < by ? curRY-- : curBY--;
					break;
					// �� ������ �ʰ� ����� ���̹Ƿ� �ش� ���� --
				case 1:
					rx < bx ? curRX-- : curBX--;
					break;
				case 2:
					ry > by ? curRY++ : curBY++;
					break;
				case 3:
					rx > bx ? curRX++ : curBX++;
					break;
				}
			}
			// �������� �Ķ����� ��ģ ��� �ʰ� ����� ������ ��ĭ �ڷ� �̵�

			if (dist[curRX][curRY][curBX][curBY] != -1)
			{
				continue;
			}
			// �̹� �ش� ��츦 ����� ���� �ִٸ� continue;
			dist[curRX][curRY][curBX][curBY] = cnt + 1;
			q.push({ curRX, curRY, curBX, curBY });
		}
	}
	
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < 10; ++k)
			{
				fill(dist[i][j][k], dist[i][j][k] + 10, -1);
			}
		}
	}
	// �Ÿ� �迭 �ʱ�ȭ

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] == 'B')
			{
				blue = { i, j };
				board[i][j] = '.';
			}
			else if (board[i][j] == 'R')
			{
				red = { i, j };
				board[i][j] = '.';
			}
		}
		// ������, �Ķ����� ��ġ�� ������ �� �ش� ��ġ�� .���� �ٲ�
	}

	cout << bfs();

	return 0;
}