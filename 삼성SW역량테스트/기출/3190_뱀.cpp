#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, K;
char board[101][101];
int snakeDirection;
deque<pair<int, int>> snake;
bool isGameOver;

void move()
{
	int headX = snake[0].first + dx[snakeDirection];
	int headY = snake[0].second + dy[snakeDirection];
	// �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��

	if (headX < 0 || headX >= N || headY < 0 || headY >= N || board[headX][headY] == '#')
	{
		isGameOver = true;
		return;
	}

	if (board[headX][headY] == 'A')
	{
		snake.push_front({ headX, headY });
		// ����� �ִٸ� ����� �������� �Ӹ��� ���� ����
	}
	else
	{
		pair<int, int> tail = snake[snake.size() - 1];
		board[tail.first][tail.second] = '.';
		// ����� �ƴ� ��� ������ ��ġ�� ĭ�� �����

		for (int i = snake.size() - 1; i > 0; --i)
		{
			snake[i] = snake[i - 1];
		}
		// snake�� ���̰� 2 �̻��� ��� �������� ��ĭ ������ �̵���Ų��
		snake[0] = { headX, headY };
		// �Ӹ��� ��ġ�� �̵���Ų��
	}

	board[headX][headY] = '#';
	// �Ӹ�ĭ�� ������ ä���
}

void change_direction(char dir)
{
	if (dir == 'D')
	{
		snakeDirection += 1;
	}
	else if (dir == 'L')
	{
		snakeDirection += 3;
	}
	snakeDirection %= 4;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		fill(board[i], board[i] + N, '.');
	}
	while (K--)
	{
		int x, y;

		cin >> x >> y;
		board[x - 1][y - 1] = 'A';
	}

	int L;
	queue<pair<int, char>> commandQueue;

	cin >> L;
	while (L--)
	{
		int X;
		char C;

		cin >> X >> C;
		commandQueue.push({ X, C });
	}

	int seconds = 0;
	snake.push_back({ 0, 0 });
	board[0][0] = '#';

	while (true)
	{
		move();
		seconds++;

		if (isGameOver == true)
		{
			cout << seconds;
			break;
		}

		if (!commandQueue.empty() && seconds == commandQueue.front().first)
		{
			change_direction(commandQueue.front().second);
			commandQueue.pop();
		}
	}
}