#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<string> maze;
int escape[1001][1001];
int fire[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R = 0;
	int C = 0;
	queue<pair<int, int>> jq;
	queue<pair<int, int>> fq;

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		string input;
		
		cin >> input;
		maze.push_back(input);
	}

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (maze[i][j] == 'J')
			{
				jq.push({ i, j });
				escape[i][j] = 1;
			}

			if (maze[i][j] == 'F')
			{
				fq.push({ i, j });
				fire[i][j] = 1;
			}
		}
	}

	while (!fq.empty())
	{
		pair<int, int> cur = fq.front();

		fq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int curX = cur.first + dx[i];
			int curY = cur.second + dy[i];

			if (curX < 0 || curX >= R || curY < 0 || curY >= C)
			{
				continue;
			}

			if (maze[curX][curY] != '.' || fire[curX][curY] != 0)
			{
				continue;
			}

			fire[curX][curY] = fire[cur.first][cur.second] + 1;
			fq.push({ curX, curY });
		}
	}

	while (!jq.empty())
	{
		pair<int, int> cur = jq.front();

		jq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int curX = cur.first + dx[i];
			int curY = cur.second + dy[i];

			if (curX < 0 || curX >= R || curY < 0 || curY >= C)
			{
				cout << escape[cur.first][cur.second];
				return 0;
			}

			if (maze[curX][curY] != '.' || escape[curX][curY] != 0)
			{
				continue;
			}

			if (fire[curX][curY] != 0 && escape[cur.first][cur.second] + 1 >= fire[curX][curY])
			{
				continue;
			}
			// fire[curX][curY] != 0 ���� ���ǿ� �ݵ�� �־�� �Ѵ�
			// �������� ���� ������ ���ϴ� ���� �ִµ� �ι�° ���ǿ� �����ʾ� �̵����� ���ϴ� ��찡 ����

			escape[curX][curY] = escape[cur.first][cur.second] + 1;
			jq.push({ curX, curY });
		}
	}

	cout << "IMPOSSIBLE";
}