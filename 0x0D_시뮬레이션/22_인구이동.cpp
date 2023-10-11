#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
int N, L, R;
int board[101][101];
bool isConnect[101][101][4];
// [i][j][dir] <= i,j 위치에서 해당 방향으로 연결되어있는가?
bool isVis[101][101];

void input() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
}

bool is_connected(int& x, int& y) {
	for (int dir = 0; dir < 4; ++dir) {
		if (isConnect[x][y][dir]) {
			return true;
		}
	}
	// 하나라도 연결돼있으면 true
	return false;
}

void move_population() {
	for (int i = 0; i < N; ++i) {
		fill(isVis[i], isVis[i] + 100, false);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (isVis[i][j] || !is_connected(i, j)) {
				continue;
			}

			queue<pair<int, int>> q;
			vector<pair<int, int>> zones;
			int totalPop = 0;
			int cnt = 0;

			isVis[i][j] = true;
			q.push({ i, j });
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				++cnt;
				zones.push_back(cur);
				totalPop += board[cur.first][cur.second];
				
				for (int dir = 0; dir < 4; ++dir) {
					int nxtX = cur.first + dx[dir];
					int nxtY = cur.second + dy[dir];

					if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N) {
						continue;
					}

					if (isVis[nxtX][nxtY]) {
						continue;
					}

					if (!isConnect[cur.first][cur.second][dir]) {
						continue;
					}

					isVis[nxtX][nxtY] = true;
					q.push({ nxtX, nxtY });
				}
			}
			
			int insertNum = totalPop / cnt;
			for (pair<int, int> zone : zones) {
				board[zone.first][zone.second] = insertNum;
			}
		}
	}
}

bool check_move() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			fill(isConnect[i][j], isConnect[i][j] + 4, false);
		}
	}

	bool isMoveable = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int dir = 0; dir < 4; ++dir) {
				int nxtX = i + dx[dir];
				int nxtY = j + dy[dir];

				if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N) {
					continue;
				}

				int gap = abs(board[i][j] - board[nxtX][nxtY]);
				if (gap >= L && gap <= R) {
					isMoveable = true;
					isConnect[i][j][dir] = true;
				}
			}
		}
	}
	// 한 칸이라도 연결됐다면 true

	return isMoveable;
}

void solution() {
	int cnt = 0;

	while (check_move()) {
		++cnt;
		move_population();
	}
	printf("%d", cnt);
}

int main() {
	input();
	solution();
}
