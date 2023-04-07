#include <iostream>
#include <vector>

using namespace std;

int sharkDX[4] = { -1, 0, 1, 0 };
int sharkDY[4] = { 0, -1, 0, 1 };
// �� �� �� ��
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};

int M, S;
vector<int> board[5][5];
pair<int, int> sharkPos;
int smellZone[5][5];

int maxKillCnt;
int tmpWayPoint;
int wayPoint;
// for dfs

bool oob(const int& x, const int& y)
{
	return (x < 1 || x > 4 || y < 1 || y > 4);
}

void move_fish()
{
	vector<int> tmpBoard[5][5];

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (board[i][j].empty())
			{
				continue;
			}

			for (int curDir : board[i][j])
			{
				bool moveFlag = false;

				for (int cnt = 0; cnt < 8; ++cnt)
				{
					int nxtX = i + dx[curDir];
					int nxtY = j + dy[curDir];
					// ���� �̵� ��ġ
					if (oob(nxtX, nxtY) == false && smellZone[nxtX][nxtY] == 0 && !(nxtX == sharkPos.first && nxtY == sharkPos.second))
					{
						moveFlag = true;
						tmpBoard[nxtX][nxtY].push_back(curDir);
						break;
					}
					curDir = (curDir + 7) % 8;
					// �̵��� �����ϸ� tmp�� �ְ� break, �׷��� �ʴٸ� (dir + 7) % 8
				}

				if (moveFlag == false)
				{
					tmpBoard[i][j].push_back(curDir);
				}
				// �ִ� 8�� ȸ�����Ѻ��� �̵��� �Ұ����ϸ� �� ��ġ �״�� tmpBoard�� ����

			}
			board[i][j].clear();
			// ��� ����Ⱑ �̵������Ƿ� ���� board �ı�
		}
	}

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (tmpBoard[i][j].empty())
			{
				continue;
			}

			for (int e : tmpBoard[i][j])
			{
				board[i][j].push_back(e);
			}
		}
	}
	// board�� tmpBoard����
}

void set_way(const int& x, const int& y, const int& moveCnt, int killCnt)
{
	if (moveCnt >= 3)
	{
		if (killCnt >= maxKillCnt)
		{
			maxKillCnt = killCnt;
			wayPoint = tmpWayPoint;
		}
		// ųī��Ʈ�� max�� ����̶��
		// �ش� wayPoint�� ����
		return;
	}

	for (int dir = 4; dir > 0; --dir)
	{
		int nxtX = x + sharkDX[dir - 1];
		int nxtY = y + sharkDY[dir - 1];
		if (oob(nxtX, nxtY) == false)
		{
			tmpWayPoint *= 10;
			tmpWayPoint += dir;
			killCnt += board[nxtX][nxtY].size();

			vector<int> tmpBoard;
			for (int e : board[nxtX][nxtY])
			{
				tmpBoard.push_back(e);
			}
			board[nxtX][nxtY].clear();

			set_way(nxtX, nxtY, moveCnt + 1, killCnt);

			for (int e : tmpBoard)
			{
				board[nxtX][nxtY].push_back(e);
			}
			killCnt -= board[nxtX][nxtY].size();
			tmpWayPoint -= dir;
			tmpWayPoint /= 10;
		}
	}
	// ���������� �����ϹǷ� 4 3 2 1 ������ �̵�
}

void practice()
{
	vector<int> tmpBoard[5][5];

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (board[i][j].empty())
			{
				continue;
			}
			for (int e : board[i][j])
			{
				tmpBoard[i][j].push_back(e);
			}
		}
	}
	// �� ���������� ����ϱ� ���� ���� board�� �����Ѵ�

	move_fish();
	set_way(sharkPos.first, sharkPos.second, 0, 0);

	int directions = 0;
	while(wayPoint > 0)
	{
		directions *= 10;
		directions += wayPoint % 10;
		wayPoint /= 10;
	}
	// wayPoint�� ������� ���ϰ� ����� �� �ִ�

	while(directions > 0)
	{
		int dir = directions % 10;
		directions /= 10;

		sharkPos.first += sharkDX[dir - 1];
		sharkPos.second += sharkDY[dir - 1];

		if (!board[sharkPos.first][sharkPos.second].empty())
		{
			board[sharkPos.first][sharkPos.second].clear();
			smellZone[sharkPos.first][sharkPos.second] = 3;
		}
	}
	// �� wayPoint �������� 3ĭ �̵��Ѵ�
	// ��� �̵��� ���������� �ռ��� ���
	// => �̵��ϴ� ������� ������ ��ȯ, ��� ���ļ� �� ���� ���� �ռ���
	// ������ �� ������ ������ �װ� remainTime�� 3�� ����⳿���� board�� �����
	// ���� �ܷ��ð� -3�� ���� => , �̹� �Ͽ��� -1 �Ǵϱ�

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (smellZone[i][j] == 0)
			{
				continue;
			}
			smellZone[i][j]--;
		}
	}
	// ��� ����⳿���� �ܷ��ð��� 1 ���δ�

	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (tmpBoard[i][j].empty())
			{
				continue;
			}
			
			for (int e : tmpBoard[i][j])
			{
				board[i][j].push_back(e);
			}
		}
	}
	// ����Ⱑ �����ȴ�
}

// ����� �̵���θ� ���ϴ� �Լ�

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> S;
	for (int i = 0; i < M; ++i)
	{
		int a, b, d;
		cin >> a >> b >> d;
		board[a][b].push_back(d - 1);
	}

	int x, y;
	cin >> x >> y;
	sharkPos.first = x;
	sharkPos.second = y;

	while (S--)
	{
		maxKillCnt = 0;
		tmpWayPoint = 0;
		

		practice();
	}

	int result = 0;
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			result += board[i][j].size();
		}
	}
	cout << result;

	return 0;
}
// ��������
// ���� �̵��ߴ� ���� �ٽ� ���ư� �� �ִ�
// DFS�� �� �� ���󺹱� ���ִ°� ������