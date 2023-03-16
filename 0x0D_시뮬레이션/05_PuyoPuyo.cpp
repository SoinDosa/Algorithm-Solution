#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int HEIGHT = 12;
const int WIDTH = 6;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
char field[HEIGHT][WIDTH];

bool isOutOfBoundary(int x, int y)
{
	if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH)
	{
		return true;
	}
	
	return false;
}

void dropPuyo()
{
	for (int i = 0; i < WIDTH; ++i)
	{
		for (int j = HEIGHT - 1; j >= 1; --j)
		{
			if (field[j][i] != '.')
			{
				continue;
			}
			// 바닥이 채워져있으면 continue
			
			for (int k = j - 1; k >= 0; --k)
			{
				if (field[k][i] != '.')
				{
					swap(field[j][i], field[k][i]);
					break;
				}
				// 시작점은 빈칸, 한 칸씩 위로 올라가며 색깔 뿌요를 만나면 빈칸과 위치를 바꾸고 반복문 종료
			}
		}
		// 아래칸부터 위에서 두번째 칸까지 탐색
	}
}

bool isPopable()
{
	bool isChecked[HEIGHT][WIDTH] = {};
	stack<pair<int, int>> popStack;

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (isChecked[i][j] == false && field[i][j] != '.')
			{
				char curColor = field[i][j];
				int linkedCnt = 0;
				queue<pair<int, int>> q;

				isChecked[i][j] = true;
				q.push({ i, j });
				while (!q.empty())
				{
					auto cur = q.front();

					popStack.push(cur);
					q.pop();
					linkedCnt++;
					for (int dir = 0; dir < 4; ++dir)
					{
						int curX = cur.first + dx[dir];
						int curY = cur.second + dy[dir];

						if (isOutOfBoundary(curX, curY))
						{
							continue;
						}

						if (isChecked[curX][curY] == true)
						{
							continue;
						}

						if (field[curX][curY] == '.' || field[curX][curY] != curColor)
						{
							continue;
						}

						isChecked[curX][curY] = true;
						q.push({ curX, curY });
					}
				}

				if (linkedCnt < 4)
				{
					for (int i = 0; i < linkedCnt; ++i)
					{
						popStack.pop();
					}
				}
			}
		}
	}

	if (popStack.empty())
	{
		return false;
	}

	else
	{
		while (!popStack.empty())
		{
			field[popStack.top().first][popStack.top().second] = '.';
			popStack.pop();
		}
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int popCnt = 0;

	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			cin >> field[i][j];
		}
	}

	while (isPopable())
	{
		popCnt++;
		dropPuyo();
	}

	cout << popCnt;

	return 0;
}