#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[9] = { 0, 1, 1, 1, 0, -1, -1, -1, 0 };
const int dy[9] = { 1, 1, 0, -1, -1, -1, 0, 1, 0 };
char board[8][8];
bool isVis[9][8][8];
// 8초가 지날 때 까지 살아남으면 탈출 가능

void input() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> board[i][j];
		}
	}
}

int solution() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 7, 0 });
	isVis[0][7][0] = true;
	// 0초에 (7, 0)에서 시작
	while (!q.empty()) {
		int curTime, curX, curY;
		tie(curTime, curX, curY) = q.front();
		q.pop();

		if (curX == 0) {
			return 1;
		}

		for (int dir = 0; dir < 9; ++dir) {
			int nxtTime = curTime + 1;
			int nxtX = curX + dx[dir];
			int nxtY = curY + dy[dir];

			if (nxtTime >= 8) {
				return 1;
			}
			// 8초가 지난 후엔 남은 벽이 없으므로 탈출 가능

			if (nxtX < 0 || nxtX >= 8 || nxtY < 0 || nxtY >= 8) {
				continue;
			}

			if (nxtX - curTime >= 0 && board[nxtX - curTime][nxtY] == '#') {
				continue;
			}
			// 가려는 칸에 벽이 존재

			if (nxtX - curTime - 1 >= 0 && board[nxtX - curTime - 1][nxtY] == '#') {
				continue;
			}
			// 가려는 칸에 벽이 내려올 예정

			if (isVis[nxtTime][nxtX][nxtY]) {
				continue;
			}

			isVis[nxtTime][nxtX][nxtY] = true;
			q.push({ nxtTime, nxtX, nxtY });
		}
	}
	return 0;
	// 탈출 방법이 없음
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	cout << solution();
	return 0;
}
