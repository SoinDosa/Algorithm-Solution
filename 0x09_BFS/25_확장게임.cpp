#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
int N, M, P;
char board[1001][1001];
int S[10];
int cnt[10];
queue<tuple<int, int, int>> q[10];
// 플레이어마다 다른 queue를 사용한다

void input() {
	cin >> N >> M >> P;
	for (int i = 1; i <= P; ++i) {
		cin >> S[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] > '0' && board[i][j] <= '9') {
				q[board[i][j] - '0'].push({ i, j, 0 });
				cnt[board[i][j] - '0']++;
			}
		}
	}
}

void solution() {
	while (true) {
		bool isExtend = false;
		for (int i = 1; i <= P; ++i) {
			queue<tuple<int, int, int>> nextQ;
			// 다음 턴에 확장할 영토 기록
			
			while (!q[i].empty()) {
				int curX, curY, curMove;
				tie(curX, curY, curMove) = q[i].front();
				q[i].pop();

				if (curMove >= S[i]) {
					nextQ.push({ curX, curY, 0 });
					continue;
				}

				for (int dir = 0; dir < 4; ++dir) {
					int nxtX = curX + dx[dir];
					int nxtY = curY + dy[dir];

					if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) {
						continue;
					}

					if (board[nxtX][nxtY] != '.') {
						continue;
					}

					q[i].push({ nxtX, nxtY, curMove + 1 });
					board[nxtX][nxtY] = (char)i + '0';
					cnt[i]++;
					isExtend = true;
				}
			}
			q[i] = nextQ;
		}
		if (!isExtend) {
			break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();

	for (int i = 1; i <= P; ++i)
	{
		cout << cnt[i] << ' ';
	}

	return 0;
}
