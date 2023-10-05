#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int N, M;
char board[1001][1001];
bool isVis[1001][1001];
pair<int, int> cnt[1001][1001];
// { id, value }
int id = 1;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}
}

void fill_cnt(const int &x, const int &y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> zones;
	int emptySize = 0;

	q.push({ x, y });
	isVis[x][y] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		++emptySize;
		zones.push_back(cur);

		for (int dir = 0; dir < 4; ++dir) {
			int nxtX = cur.first + dx[dir];
			int nxtY = cur.second + dy[dir];

			if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) {
				continue;
			}

			if (board[nxtX][nxtY] == '1') {
				continue;
			}

			if (isVis[nxtX][nxtY]) {
				continue;
			}

			q.push({ nxtX, nxtY });
			isVis[nxtX][nxtY] = true;
		}
	}

	for (pair<int, int> zone : zones) {
		cnt[zone.first][zone.second] = { id, emptySize };
	}
	// id로 같은 칸의 여부를 구분한다
}

void solution() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == '0' && !isVis[i][j]) {
				fill_cnt(i, j);
				++id;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (board[i][j] == '0') {
				cout << 0;
				continue;
			}

			int total = 0;
			vector<int> visitedID;
			for (int dir = 0; dir < 4; ++dir) {
				int nxtX = i + dx[dir];
				int nxtY = j + dy[dir];

				if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) {
					continue;
				}

				bool addable = true;
				for (int visited : visitedID) {
					if (visited == cnt[nxtX][nxtY].first) {
						addable = false;
						break;
					}
				}

				if (!addable) {
					continue;
				}

				total += cnt[nxtX][nxtY].second;
				visitedID.push_back(cnt[nxtX][nxtY].first);
			}
			cout << (total + 1) % 10;
		}
		cout << '\n';
	}
}

int main() {
	input();
	solution();

	return 0;
}
