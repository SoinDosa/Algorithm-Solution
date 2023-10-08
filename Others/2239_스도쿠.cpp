#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[9][9];
bool isUsedRow[9][9];
// [i][num] i번째 row에서 이미 num이 사용됐다
bool isUsedCol[9][9];
// [j][num] j번째 col에서 이미 num이 사용됐다
bool isUsedSq[9][9];
// [pos][num] pos번째 정사각형에서 이미 num이 사용됐다
bool isComplete;

void input() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%1d", &board[i][j]);
			if (board[i][j] != 0) {
				isUsedRow[i][board[i][j]] = true;
				isUsedCol[j][board[i][j]] = true;
				isUsedSq[(i / 3) * 3 + (j / 3)][board[i][j]] = true;
			}
		}
	}
}

void dfs(int cur) {
	if (cur == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	int curRow = cur / 9;
	int curCol = cur % 9;

	if (board[curRow][curCol] == 0) {
		for (int i = 1; i <= 9; ++i) {
			if (isUsedRow[curRow][i] || isUsedCol[curCol][i] || isUsedSq[(curRow / 3) * 3 + (curCol / 3)][i]) {
				continue;
			}

			isUsedRow[curRow][i] = true;
			isUsedCol[curCol][i] = true;
			isUsedSq[(curRow / 3) * 3 + (curCol / 3)][i] = true;

			board[curRow][curCol] = i;
			dfs(cur + 1);
			board[curRow][curCol] = 0;
			isUsedSq[(curRow / 3) * 3 + (curCol / 3)][i] = false;
			isUsedCol[curCol][i] = false;
			isUsedRow[curRow][i] = false;
		}
	}
	else {
		dfs(cur + 1);
	}
}

void solution() {
	dfs(0);
}

int main() {
	input();
	solution();

	return 0;
}
