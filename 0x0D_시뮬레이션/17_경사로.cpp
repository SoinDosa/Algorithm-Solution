#include <iostream>

using namespace std;

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int N, L;
int board[101][101];

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= N);
}

bool isWay(int x, int y, int dir)
{
	bool isRoad[101][101] = {};

	for (int i = 0; i < N - 1; ++i)
	{
		int cur = board[x][y];
		int nxtX = x + dx[dir];
		int nxtY = y + dy[dir];
		int nxt = board[nxtX][nxtY];

		if (cur == nxt)
		{
			x = nxtX;
			y = nxtY;
		}
		// 다음 길과 높이가 같으면 넘어감
		else if (cur - nxt == 1)
		{
			for (int j = 0; j < L; ++j)
			{
				x += dx[dir];
				y += dy[dir];

				if (oob(x, y) == true)
				{
					return false;
				}

				if (board[x][y] != nxt)
				{
					return false;
				}
				isRoad[x][y] = true;
			}
			i += (L - 1);
			// 다리 놓기에 성공했다면 i를 L - 1만큼 증가
			// L - 1인 이유 : for문 끝나면 ++i 되니까
		}
		// 다음 길이 현재 높이보다 1 낮을 경우 L만큼 다리를 놓는 시도를 한다
		// 여기선 경사로를 놓으며 x, y를 증가시켜야한다
		else if (cur - nxt == -1)
		{
			int tmpX = x;
			int tmpY = y;

			if (isRoad[tmpX][tmpY] == true)
			{
				return false;
			}
			isRoad[tmpX][tmpY] = true;
			// 현재 위치에 경사로를 설치할 수 있다면 설치
			for (int i = 0; i < L - 1; ++i)
			{
				tmpX -= dx[dir];
				tmpY -= dy[dir];

				if (oob(tmpX, tmpY) == true)
				{
					return false;
				}

				if (board[tmpX][tmpY] != cur)
				{
					return false;
				}

				if (isRoad[tmpX][tmpY] == true)
				{
					return false;
				}
				// 뒤로 경사로를 놓으려는데 이미 설치돼있으면 실패
			}
			x = nxtX;
			y = nxtY;
			// 뒤로 경사로를 정상적으로 놓을 수 있다면 한 칸 전진
		}
		// 다음 길이 현재 높이보다 1 높을 경우 L만큼 경사로를 뒤로 놓는 시도를 한다
		else
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> L;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		if (isWay(0, i, 0))
		{
			cnt++;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (isWay(i, 0, 1))
		{
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}