#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int N, M, K;
char board[1001][1001];
int dist[1001][1001][11];

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> board[i][j];
		}
	}
	dist[1][1][0] = 1;
}

int solution() {
	queue<tuple<int, int, int>> q;

	if (N == 1 && M == 1) {
		return 1;
	}

	q.push({ 1, 1, 0 });
	while (!q.empty()) {
		int curX, curY, curK;
		tie(curX, curY, curK) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nxtX = curX + dx[dir];
			int nxtY = curY + dy[dir];

			if (nxtX < 1 || nxtX > N || nxtY < 1 || nxtY > M) {
				continue;
			}

			if (dist[nxtX][nxtY][curK] != 0) {
				continue;
			}

			if (nxtX == N && nxtY == M)
			{
				return dist[curX][curY][curK] + 1;
			}


			if (board[nxtX][nxtY] == '1') {
				if (curK >= K || dist[nxtX][nxtY][curK + 1] != 0) {
					continue;
				}
				// 오답 정리 : dist[nxtX][nxtY][curK + 1]에 값 갱신할건데
				// 이미 있으면 안되지!

				dist[nxtX][nxtY][curK + 1] = dist[curX][curY][curK] + 1;
				q.push({ nxtX, nxtY, curK + 1 });
			}
			else
			{
				dist[nxtX][nxtY][curK] = dist[curX][curY][curK] + 1;
				q.push({ nxtX, nxtY, curK });
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	cout << solution();
}
