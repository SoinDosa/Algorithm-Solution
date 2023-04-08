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
// {a�� b���̿� ���� �ִ�}
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
			// ��ǳ���� ������ 0, 2�� ���, Y�� ������ ���밪�� 1�̸� addTemper�� 1 �����
			else
			{
				if (abs(prevPos.first - cur.first) == 1)
				{
					addTemper--;
				}
			}
			// ��ǳ���� ������ 1, 3�� ���,  X�� ������ ���밪�� 1�̸� addTemper�� 1 �����

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
				// ���� ������� üũ

				if (!(cur.first == nxt.first && cur.second == nxt.second))
				{
					if (isWall[cur.first][cur.second][nxt.first][nxt.second] == true)
					{
						continue;
					}
				}
				// ���� ��ġ�� �ƴϰ� ���� �������� üũ

				nxt.first += dx[warmerDir];
				nxt.second += dy[warmerDir];
				// ��ǳ�� ���⸸ŭ ����

				if (oob(nxt.first, nxt.second) == true)
				{
					continue;
				}
				// ���� ������� �ѹ� �� üũ
				if (isWall[nxt.first - dx[warmerDir]][nxt.second - dy[warmerDir]][nxt.first][nxt.second] == true)
				{
					continue;
				}
				// ���� �������� �� �� �� üũ
				q.push({ nxt.first, nxt.second });
				// ť�� ����
			}
			// ���� ���� üũ
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
	// ���� �ִ� ��� ��ǳ�⿡�� �ٶ��� ����

	set_temper();
	// �µ��� ������

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
	// ���ݸ��� �ϳ� �Դ´�
	// �����ϴ� ��� ĭ�� �µ��� K �̻��� �Ǿ����� �˻��Ѵ�

	return isGood;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0;

	cin >> R >> C >> K;
	// ���� R, C, K�� �־�����
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
				// ���� ���� ����� ���� ���� ������ ������ �־��ش�
				warmerZone.push_back({ i, j, dir });
			}
		}
	}
	// R���� �ٿ� ���� ������ �־����� {i, j}
	
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
		// ��������
		// isWall[x][y] = true;
		// isWall[x][y + 1] = true; �̷������� ���� ����� �ǵ�ġ���� ���� ��������� ��찡 ����
	}
	// ���� ���� W�� �־����� {x, y, t}, t�� 0�� ��� {x,y}{x-1,y} ����, 1�� ��� {x,y},{x,y+1}

	while (is_good_temper() == false)
	{

	}

	cout << chocolate;
	// �Դ� ���ݸ��� ����(������ ������ ������ �ٶ��� ��� ���Դ°�?)

	return 0;
}