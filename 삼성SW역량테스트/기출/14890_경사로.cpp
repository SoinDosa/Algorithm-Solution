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
		// ���� ��� ���̰� ������ �Ѿ
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
			// �ٸ� ���⿡ �����ߴٸ� i�� L - 1��ŭ ����
			// L - 1�� ���� : for�� ������ ++i �Ǵϱ�
		}
		// ���� ���� ���� ���̺��� 1 ���� ��� L��ŭ �ٸ��� ���� �õ��� �Ѵ�
		// ���⼱ ���θ� ������ x, y�� �������Ѿ��Ѵ�
		else if (cur - nxt == -1)
		{
			int tmpX = x;
			int tmpY = y;

			if (isRoad[tmpX][tmpY] == true)
			{
				return false;
			}
			isRoad[tmpX][tmpY] = true;
			// ���� ��ġ�� ���θ� ��ġ�� �� �ִٸ� ��ġ
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
				// �ڷ� ���θ� �������µ� �̹� ��ġ�������� ����
			}
			x = nxtX;
			y = nxtY;
			// �ڷ� ���θ� ���������� ���� �� �ִٸ� �� ĭ ����
		}
		// ���� ���� ���� ���̺��� 1 ���� ��� L��ŭ ���θ� �ڷ� ���� �õ��� �Ѵ�
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