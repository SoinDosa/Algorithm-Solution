#include <iostream>
using namespace std;

const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { 1, 0, -1, 0 };

int R, C;
char board[21][21];
bool isUsed[26];
// 알파벳 사용 여부
int maxCnt;

void input() {
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
		}
	}
}

void backtracking(int x, int y, int cnt) {
	for (int dir = 0; dir < 4; ++dir) {
		int nxtX = x + dx[dir];
		int nxtY = y + dy[dir];

		if (nxtX < 0 || nxtX >= R || nxtY < 0 || nxtY >= C) {
			continue;
		}

		if (isUsed[board[nxtX][nxtY] - 'A']) {
			continue;
		}
		
		isUsed[board[nxtX][nxtY] - 'A'] = true;
		backtracking(nxtX, nxtY, cnt + 1);
		isUsed[board[nxtX][nxtY] - 'A'] = false;
	}

	maxCnt = max(maxCnt, cnt);
}

void solution() {
	isUsed[board[0][0] - 'A'] = true;
	backtracking(0, 0, 1);

	cout << maxCnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();
}
