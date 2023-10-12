#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int N, M, K;
int A[11][11];
int energy[11][11];
deque<int> trees[11][11];
queue<int> deads[11][11];
queue<int> canExpand[11][11];

void init() {
	for (int i = 1; i <= N; ++i) {
		fill(energy[i] + 1, energy[i] + 1 + N, 5);
	}
}
void input() {
	scanf("%d %d %d", &N, &M, &K);
	init();
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &A[i][j]);
		}
	}

	int x, y, z;
	while(M--) {
		scanf("%d %d %d", &x, &y, &z);
		trees[x][y].push_back(z);
		// 입력으로 주어지는 나무의 위치는 모두 서로 다르므로 따로 정렬처리 X
	}
}

void spring() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (trees[i][j].empty()) {
				continue;
			}

			queue<int> growTrees;
			while (!trees[i][j].empty()) {
				int curTree = trees[i][j].front();
				trees[i][j].pop_front();

				if (energy[i][j] < curTree) {
					deads[i][j].push(curTree);
					continue;
				}

				energy[i][j] -= curTree;
				curTree++;

				if (curTree % 5 == 0) {
					canExpand[i][j].push(1);
				}

				growTrees.push(curTree);
			}

			while (!growTrees.empty()) {
				int curTree = growTrees.front();
				growTrees.pop();
				trees[i][j].push_back(curTree);
				// 어차피 어린 나무부터 나이가 먹고 큐에 들어가므로 push_back
			}
		}
	}
}

void summer() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (deads[i][j].empty()) {
				continue;
			}

			while (!deads[i][j].empty()) {
				int curTree = deads[i][j].front();
				deads[i][j].pop();

				energy[i][j] += curTree / 2;
			}
		}
	}
}

void fall() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (canExpand[i][j].empty()) {
				continue;
			}

			while (!canExpand[i][j].empty()) {
				canExpand[i][j].pop();

				for (int dir = 0; dir < 8; ++dir) {
					int nxtX = i + dx[dir];
					int nxtY = j + dy[dir];

					if (nxtX <= 0 || nxtX > N || nxtY <= 0 || nxtY > N) {
						continue;
					}

					trees[nxtX][nxtY].push_front(1);
					// 1살이면 무조건 가장 어린 나무므로 앞에 넣는다
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			energy[i][j] += A[i][j];
		}
	}
}

void solution() {
	while (K--) {
		spring();
		summer();
		fall();
		winter();
	}

	int total = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			total += trees[i][j].size();
		}
	}
	printf("%d", total);
}

int main() {
	input();
	solution();

	return 0;
}
