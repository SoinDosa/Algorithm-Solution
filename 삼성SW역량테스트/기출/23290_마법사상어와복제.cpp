#include <iostream>
#include <vector>

using namespace std;

int sharkDX[4] = { -1, 0, 1, 0 };
int sharkDY[4] = { 0, -1, 0, 1 };
// 상 좌 하 우
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
					// 다음 이동 위치
					if (oob(nxtX, nxtY) == false && smellZone[nxtX][nxtY] == 0 && !(nxtX == sharkPos.first && nxtY == sharkPos.second))
					{
						moveFlag = true;
						tmpBoard[nxtX][nxtY].push_back(curDir);
						break;
					}
					curDir = (curDir + 7) % 8;
					// 이동이 가능하면 tmp에 넣고 break, 그렇지 않다면 (dir + 7) % 8
				}

				if (moveFlag == false)
				{
					tmpBoard[i][j].push_back(curDir);
				}
				// 최대 8번 회전시켜보고 이동이 불가능하면 그 위치 그대로 tmpBoard에 넣음

			}
			board[i][j].clear();
			// 모든 물고기가 이동했으므로 기존 board 파기
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
	// board에 tmpBoard복사
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
		// 킬카운트가 max인 방법이라면
		// 해당 wayPoint로 설정
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
	// 사전순으로 가야하므로 4 3 2 1 방향대로 이동
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
	// 상어가 복제마법을 사용하기 위해 현재 board를 복사한다

	move_fish();
	set_way(sharkPos.first, sharkPos.second, 0, 0);

	int directions = 0;
	while(wayPoint > 0)
	{
		directions *= 10;
		directions += wayPoint % 10;
		wayPoint /= 10;
	}
	// wayPoint를 뒤집어야 편하게 사용할 수 있다

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
	// 상어가 wayPoint 방향으로 3칸 이동한다
	// 상어 이동에 사전순으로 앞서는 방법
	// => 이동하는 방향들을 정수로 변환, 모두 합쳐서 더 작은 수가 앞선다
	// 물고기와 상어가 만나면 물고기는 죽고 remainTime이 3인 물고기냄새를 board에 남긴다
	// 냄새 잔류시간 -3인 이유 => , 이번 턴에서 -1 되니까

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
	// 모든 물고기냄새의 잔류시간을 1 줄인다

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
	// 물고기가 복제된다
}

// 상어의 이동경로를 정하는 함수

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
// 오답정리
// 상어는 이동했던 곳을 다시 돌아갈 수 있다
// DFS할 때 값 원상복구 해주는거 잘하자