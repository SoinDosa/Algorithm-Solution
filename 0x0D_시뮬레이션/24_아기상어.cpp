#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, -1, 0, 1 };

int N;
int sX, sY;
int sharkSize = 2;
int fish[21][21];
int curEat;
int totalTime;

void input() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &fish[i][j]);

			if (fish[i][j] == 9) {
				sX = i;
				sY = j;
				fish[i][j] = 0;
			}
		}
	}
}

bool can_eat() {
	queue<pair<int, int>> q;
	int dist[21][21] = {};
	vector<tuple<int, int, int>> fishPos;
	// cost, x, y

	dist[sX][sY] = 1;
	q.push({ sX, sY });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nxtX = cur.first + dx[dir];
			int nxtY = cur.second + dy[dir];

			if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= N) {
				continue;
			}

			if (fish[nxtX][nxtY] > sharkSize) {
				continue;
			}

			if (dist[nxtX][nxtY] != 0) {
				continue;
			}

			if (fish[nxtX][nxtY] != 0 && fish[nxtX][nxtY] < sharkSize) {
				fishPos.push_back({ dist[cur.first][cur.second], nxtX, nxtY });
			}

			dist[nxtX][nxtY] = dist[cur.first][cur.second] + 1;
			q.push({ nxtX, nxtY });
		}
	}

	if (fishPos.empty()) {
		return false;
	}

	sort(fishPos.begin(), fishPos.end());
	int eatFishTime, eatX, eatY;
	tie(eatFishTime, eatX, eatY) = fishPos[0];

	totalTime += eatFishTime;
	fish[eatX][eatY] = 0;
	curEat++;
	sX = eatX;
	sY = eatY;

	if (curEat >= sharkSize) {
		sharkSize++;
		curEat = 0;
	}

	return true;
}

void solution() {
	while (true) {
		if (!can_eat()) {
			break;
		}
	}

	printf("%d", totalTime);
}

int main() {
	input();
	solution();

	return 0;
}
