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
	// 지도의 바깥으로 이동시키려고 하는 경우 명령 무시

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
	// 주사위를 해당 방향으로 굴린다

	if (board[x][y] == 0)
	{
		board[x][y] = dice[5];
	}
	// 지도 칸이 0이라면 주사위 바닥면의 숫자를 복사
	else
	{
		dice[5] = board[x][y];
		board[x][y] = 0;
	}
	// 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사
	// 칸에 쓰인 숫자는 0이 됨

	cout << dice[0] << '\n';
	// 상단에 쓰인 값을 출력
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