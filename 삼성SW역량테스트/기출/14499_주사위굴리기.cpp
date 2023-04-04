#include <iostream>

using namespace std;

int N;
int M;
int x;
int y;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int board[21][21];
int dice[6];
// 0 : top, 1 : right, 2: left, 3: up, 4: down, 5 : bottom

bool isOutOfBoundary(int curX, int curY)
{
	return (curX < 0 || curX >= N || curY < 0 || curY >= M);
}

void moveDice(int dir)
{
	x += dx[dir - 1];
	y += dy[dir - 1];

	if (isOutOfBoundary(x, y) == true)
	{
		x -= dx[dir - 1];
		y -= dy[dir - 1];
		return;
	}
	// ������ �ٱ����� �̵���Ű���� �ϴ� ��� ��� ����

	int temp = dice[0];
	switch (dir)
	{
	case 1:
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
		break;
	case 2:
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[2];
		dice[2] = temp;
		break;
	case 3:
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[3];
		dice[3] = temp;
		break;
	case 4:
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[4];
		dice[4] = temp;
		break;
	}
	// �ֻ����� �ش� �������� ������

	if (board[x][y] == 0)
	{
		board[x][y] = dice[5];
	}
	// ���� ĭ�� 0�̶�� �ֻ��� �ٴڸ��� ���ڸ� ����
	else
	{
		dice[5] = board[x][y];
		board[x][y] = 0;
	}
	// 0�� �ƴ� ��쿡�� ĭ�� ���� �ִ� ���� �ֻ����� �ٴڸ����� ����
	// ĭ�� ���� ���ڴ� 0�� ��

	cout << dice[0] << '\n';
	// ��ܿ� ���� ���� ���
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K = 0;

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	while (K--)
	{
		int dir = 0;
		
		cin >> dir;
		moveDice(dir);
	}

	return 0;
}