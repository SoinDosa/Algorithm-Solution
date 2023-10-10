#include <iostream>
#include <queue>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
// 0: 동, 1: 남, 2: 서, 3: 북
int dice[6];
// 0: 위, 1: 아래, 2: 앞, 3: 뒤, 4: 왼, 5: 오
int board[21][21];
int diceX, diceY;
int dir;

int N, M, K;

void init() {
	dice[0] = 1;
	dice[1] = 6;
	dice[2] = 5;
	dice[3] = 2;
	dice[4] = 4;
	dice[5] = 3;
	diceX = 0; diceY = 0;
	dir = 0;
}

void input() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
}

void copy_dice(int* mDice) {
	for (int i = 0; i < 6; ++i) {
		dice[i] = mDice[i];
	}
}

void move_dice() {
	diceX += dx[dir];
	diceY += dy[dir];
	if (diceX < 0 || diceX >= N || diceY < 0 || diceY >= M) {
		diceX -= dx[dir];
		diceY -= dy[dir];

		dir = (dir + 2) % 4;

		diceX += dx[dir];
		diceY += dy[dir];
	}

	if (dir == 0) {
		int tempDice[6] = { dice[4], dice[5], dice[2], dice[3], dice[1], dice[0] };
		copy_dice(tempDice);
	}
	else if (dir == 1) {
		int tempDice[6] = { dice[3], dice[2], dice[0], dice[1], dice[4], dice[5] };
		copy_dice(tempDice);
	}
	else if (dir == 2) {
		int tempDice[6] = { dice[5], dice[4], dice[2], dice[3], dice[0], dice[1] };
		copy_dice(tempDice);
	}
	else if (dir == 3) {
		int tempDice[6] = { dice[2], dice[3], dice[1], dice[0], dice[4], dice[5] };
		copy_dice(tempDice);
	}
}

int calc_score() {
	int cnt = 0;
	bool isVis[21][21] = {};
	queue<pair<int, int>> q;
	int num = board[diceX][diceY];

	isVis[diceX][diceY] = true;
	q.push({ diceX, diceY });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		++cnt;

		for (int d = 0; d < 4; ++d) {
			int nxtX = cur.first + dx[d];
			int nxtY = cur.second + dy[d];

			if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) {
				continue;
			}

			if (isVis[nxtX][nxtY]) {
				continue;
			}

			if (board[nxtX][nxtY] != num) {
				continue;
			}

			isVis[nxtX][nxtY] = true;
			q.push({ nxtX, nxtY });
		}
	}

	return cnt * num;
}

void calc_dir() {
	int A = dice[1];
	int B = board[diceX][diceY];

	if (A > B) {
		dir = (dir + 1) % 4;
	}
	else if (A < B) {
		dir = (dir + 3) % 4;
	}
}

void solution() {
	int totalScore = 0;

	while (K--) {
		move_dice();
		totalScore += calc_score();
		calc_dir();
	}

	printf("%d\n", totalScore);
}

int main() {
	init();
	input();
	solution();

	return 0;
}
