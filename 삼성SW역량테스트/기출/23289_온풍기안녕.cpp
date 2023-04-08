#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
const int INIT_TEMPER = 5;

int R, C, K;
int W;
int roomMap[21][21];
bool isWall[21][21][21][21];
int roomTemper[21][21];
// {1,1} ~ {R,C}
vector<tuple<int, int, int>> warmerZone;
vector<pair<int, int>> checkZone;
// {a와 b사이에 벽이 있다}
int chocolate;

bool oob(const int& x, const int& y)
{
	return (x < 1 || x > R || y < 1 || y > C);
}

void turn_warmer()
{
	for (tuple<int, int, int> curWarmer : warmerZone)
	{
		int warmerX, warmerY, warmerDir;
		queue<pair<int, int>> q;
		int addTemperMap[21][21] = {};
		int addTemper = INIT_TEMPER;
		pair<int, int> prevPos;

		tie(warmerX, warmerY, warmerDir) = curWarmer;
		q.push({ warmerX + dx[warmerDir], warmerY + dy[warmerDir] });
		prevPos = { warmerX + dx[warmerDir], warmerY + dy[warmerDir] };

		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();

			if (warmerDir == 0 || warmerDir == 2)
			{
				if (abs(prevPos.second - cur.second) == 1)
				{
					addTemper--;
				}
			}
			// 온풍기의 방향이 0, 2일 경우, Y축 간격의 절대값이 1이면 addTemper를 1 낮춘다
			else
			{
				if (abs(prevPos.first - cur.first) == 1)
				{
					addTemper--;
				}
			}
			// 온풍기의 방향이 1, 3일 경우,  X축 간격의 절대값이 1이면 addTemper를 1 낮춘다

			if (addTemper == 0)
			{
				break;
			}
			prevPos = cur;

			if (addTemperMap[cur.first][cur.second] == 0)
			{
				addTemperMap[cur.first][cur.second] = addTemper;
			}

			pair<int, int> direction1 = { cur.first + dx[(warmerDir + 1) % 4], cur.second + dy[(warmerDir + 1) % 4] };
			pair<int, int> direction2 = { cur.first, cur.second };
			pair<int, int> direction3 = { cur.first + dx[(warmerDir + 3) % 4], cur.second + dy[(warmerDir + 3) % 4] };
			for (pair<int, int> nxt : { direction1, direction2, direction3 })
			{
				if (oob(nxt.first, nxt.second) == true)
				{
					continue;
				}
				// 범위 벗어나는지 체크

				if (!(cur.first == nxt.first && cur.second == nxt.second))
				{
					if (isWall[cur.first][cur.second][nxt.first][nxt.second] == true)
					{
						continue;
					}
				}
				// 본래 위치가 아니고 벽에 막혔는지 체크

				nxt.first += dx[warmerDir];
				nxt.second += dy[warmerDir];
				// 온풍기 방향만큼 전진

				if (oob(nxt.first, nxt.second) == true)
				{
					continue;
				}
				// 범위 벗어나는지 한번 더 체크
				if (isWall[nxt.first - dx[warmerDir]][nxt.second - dy[warmerDir]][nxt.first][nxt.second] == true)
				{
					continue;
				}
				// 벽에 막혔는지 한 번 더 체크
				q.push({ nxt.first, nxt.second });
				// 큐에 삽입
			}
			// 다음 방향 체크
		}
		for (int i = 1; i <= R; ++i)
		{
			for (int j = 1; j <= C; ++j)
			{
				roomTemper[i][j] += addTemperMap[i][j];
			}
		}
	}
}

void set_temper()
{
	int tempRoom[21][21] = {};

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			int temperGap = 0;

			if (i != R)
			{
				if (isWall[i][j][i + 1][j] == false)
				{
					temperGap = (roomTemper[i][j] - roomTemper[i + 1][j]);
					if (temperGap != 0)
					{
						temperGap /= 4;
						tempRoom[i][j] -= temperGap;
						tempRoom[i + 1][j] += temperGap;
					}
				}
			}

			if (j != C)
			{
				if (isWall[i][j][i][j + 1] == false)
				{
					temperGap = (roomTemper[i][j] - roomTemper[i][j + 1]);
					if (temperGap != 0)
					{
						temperGap /= 4;
						tempRoom[i][j] -= temperGap;
						tempRoom[i][j + 1] += temperGap;
					}
				}
			}
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			roomTemper[i][j] += tempRoom[i][j];
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		if (i == 1 || i == R)
		{
			for (int j = 1; j <= C; ++j)
			{
				if (roomTemper[i][j] == 0)
				{
					continue;
				}
				roomTemper[i][j] -= 1;
			}
		}
		else
		{
			if (roomTemper[i][1] != 0)
			{
				roomTemper[i][1] -= 1;
			}

			if (roomTemper[i][C] != 0)
			{
				roomTemper[i][C] -= 1;
			}
		}
	}
}

bool check_zone_temper()
{
	for (pair<int, int> cur : checkZone)
	{
		if (roomTemper[cur.first][cur.second] < K)
		{
			return false;
		}
	}

	return true;
}

bool is_good_temper()
{
	turn_warmer();
	// 집에 있는 모든 온풍기에서 바람이 나옴

	set_temper();
	// 온도가 조절됨

	chocolate++;

	bool isGood;
	if (chocolate > 100)
	{
		isGood = true;
	}
	else
	{
		isGood = check_zone_temper();
	}
	// 초콜릿을 하나 먹는다
	// 조사하는 모든 칸의 온도가 K 이상이 되었는지 검사한다

	return isGood;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0;

	cin >> R >> C >> K;
	// 정수 R, C, K가 주어진다
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> roomMap[i][j];
			if (roomMap[i][j] == 0)
			{
				continue;
			}

			if (roomMap[i][j] == 5)
			{
				checkZone.push_back({ i, j });
			}
			else
			{
				int dir = 0;
				switch (roomMap[i][j])
				{
				case 1:
					dir = 0;
					break;
				case 2:
					dir = 2;
					break;
				case 3:
					dir = 3;
					break;
				case 4:
					dir = 1;
					break;
				}
				// 편한 방향 계산을 위해 새로 적용한 방향을 넣어준다
				warmerZone.push_back({ i, j, dir });
			}
		}
	}
	// R개의 줄에 방의 정보가 주어진다 {i, j}
	
	cin >> W;
	while (W--)
	{
		int x, y, t;
		
		cin >> x >> y >> t;
		if (t == 0)
		{
			isWall[x][y][x -1][y] = true;
			isWall[x - 1][y][x][y] = true;
		}
		else
		{
			isWall[x][y][x][y + 1] = true;
			isWall[x][y + 1][x][y] = true;
		}
		// 오답정리
		// isWall[x][y] = true;
		// isWall[x][y + 1] = true; 이런식으로 벽을 세우면 의도치않은 벽이 만들어지는 경우가 있음
	}
	// 벽의 개수 W가 주어진다 {x, y, t}, t가 0인 경우 {x,y}{x-1,y} 사이, 1인 경우 {x,y},{x,y+1}

	while (is_good_temper() == false)
	{

	}

	cout << chocolate;
	// 먹는 초콜릿의 갯수(조건을 만족할 때까지 바람이 몇번 나왔는가?)

	return 0;
}