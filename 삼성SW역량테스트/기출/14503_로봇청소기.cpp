#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M;
int R, C, d;
int board[51][51];

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int bfs()
{
	queue<pair<int, int>> q;
	bool isClean[51][51] = {};
	int curDir = d;
	int cleanCnt = 0;

	q.push({ R, C });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		if (isClean[cur.first][cur.second] == false)
		{
			isClean[cur.first][cur.second] = true;
			cleanCnt++;
		}
		// ���� ĭ�� û�ҵ��� ���� ��� ���� ĭ�� û��
		
		bool isCatchDirty = false;

		for (int dir = 0; dir < 4; ++dir)
		{
			int curX = cur.first + dx[dir];
			int curY = cur.second + dy[dir];

			if (oob(curX, curY) == true)
			{
				continue;
			}

			if (board[curX][curY] != 1 && isClean[curX][curY] == false)
			{
				isCatchDirty = true;
			}
		}
		// �ֺ� 4ĭ�� û�ҵ��� �ʾҴ��� üũ
		
		if (isCatchDirty == false)
		{
			int backX = cur.first - dx[curDir];
			int backY = cur.second - dy[curDir];

			if (oob(backX, backY) == true || board[backX][backY] == 1)
			{
				return cleanCnt;
			}
			else
			{
				q.push({ backX, backY });
			}
		}
		// 4ĭ �� û�ҵƴٸ� ������ �����ϸ� ��ĭ ���� �� continue
		// ������ �Ұ����ϴٸ� �۵� ����
		else
		{
			do {
				curDir = (curDir + 3) % 4;
			} while (!(board[cur.first + dx[curDir]][cur.second + dy[curDir]] == 0 && isClean[cur.first + dx[curDir]][cur.second + dy[curDir]] == false));
			
			q.push({ cur.first + dx[curDir], cur.second + dy[curDir] });
		}
		// û�ҵ��� ���� ĭ�� �ִ� ���  curDir + 3 % 4
		// û�ҵ��� ���� ĭ�� ���� �� ���� ȸ��
		// ��ĭ ����
	}

	return cleanCnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	cin >> R >> C >> d;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}
	cout << bfs();

	return 0;
}