#include <iostream>
#include <vector>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
const int bDirx[4] = { -1, 1, 0, 0 };
const int bDiry[4] = { 0, 0, -1, 1 };
int N, M;
int board[50][50];
vector<int> linearBoard;
// 구슬의 상태를 선형으로 보관
vector<pair<int, int>> blockPos;
// 방향대로 갔을 때 n번 블록의 좌표
int poped[4];

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			scanf("%d", &board[i][j]);
		}
	}
}

void get_block_pos() {
	int x = (N + 1) / 2;
	int y = (N + 1) / 2;
	int dir = 0;
	int cnt = 0;
	int directCnt = 0;
	int maxDirect = 1;
	int turnCnt = 0;
	// turnCnt가 2회면 moveCnt + 1
	while (true) {
		if (cnt == N * N) {
			break;
		}
		blockPos.push_back({ x, y });
		cnt++;
		directCnt++;

		x += dx[dir];
		y += dy[dir];

		if (directCnt == maxDirect) {
			dir = (dir + 1) % 4;
			directCnt = 0;
			turnCnt++;

			if (turnCnt % 2 == 0) {
				maxDirect++;
			}
		}
	}
}

void copy_vector(vector<int>& a, vector<int>& b) {
	for (int e : b) {
		if (e == 0) {
			continue;
		}
		a.push_back(e);

		if (a.size() >= N * N - 1) {
			break;
		}
	}
}

void reset_board() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			board[i][j] = 0;
		}
	}

	for (int i = 0; i < linearBoard.size(); ++i) {
		pair<int, int> pos = blockPos[i + 1];
		board[pos.first][pos.second] = linearBoard[i];
	}
}

void create() {
	vector<int> temp;

	int curColor = linearBoard[0];
	int cnt = 1;
	for (int i = 1; i < linearBoard.size(); ++i) {
		if (linearBoard[i] == curColor) {
			cnt++;
		}
		else {
			temp.push_back(cnt);
			temp.push_back(curColor);

			cnt = 1;
			curColor = linearBoard[i];
		}
		// 색깔이 달라졌다면 같은 그룹이라는 뜻
	}
	temp.push_back(cnt);
	temp.push_back(curColor);
	// 마지막 원소도 넣어준다

	linearBoard.clear();
	copy_vector(linearBoard, temp);
	// 변형된 값을 linear에 복사
}

void explosion() {
	vector<int> tempLinear;
	vector<int> popPos;
	int curNum = 0;
	int contCnt = 0;
	bool isBomb;

	do {
		tempLinear.clear();
		isBomb = false;
		for (int i = 0; i < linearBoard.size(); ++i) {
			if (linearBoard[i] == curNum) {
				contCnt++;
				popPos.push_back(i);
			}
			else {
				if (contCnt >= 4) {
					for (int pos : popPos) {
						poped[curNum]++;
						linearBoard[pos] = 0;
					}
					isBomb = true;
				}
				popPos.clear();
				popPos.push_back(i);
				curNum = linearBoard[i];
				contCnt = 1;
			}
			// 색깔이 달라짐 => 폭파 여부 결정
		}
		if (contCnt >= 4) {
			for (int pos : popPos) {
				poped[curNum]++;
				linearBoard[pos] = 0;
			}
			isBomb = true;
		}
		popPos.clear();
		curNum = 0;
		contCnt = 1;
		// 맨 마지막 원소도 폭파시킨 후 원상복구

		copy_vector(tempLinear, linearBoard);
		// 0을 제거한 결과를 temp에 복사
		linearBoard.clear();
		copy_vector(linearBoard, tempLinear);
		// temp를 다시 linear에 복사
	} while (isBomb);
	// 폭발이 없을 때까지 반복
}

void blizzard(int d, int s) {
	int x = (N + 1) / 2;
	int y = (N + 1) / 2;
	linearBoard.clear();

	while (s--) {
		x += bDirx[d - 1];
		y += bDiry[d - 1];
		board[x][y] = 0;
	}

	for (pair<int, int> pos : blockPos) {
		if (board[pos.first][pos.second] == 0) {
			continue;
		}
		linearBoard.push_back(board[pos.first][pos.second]);
	}
	// 일직선 기술로 파괴된 구슬빼고 삽입
}

void solution() {
	get_block_pos();
	
	int d, s;
	while (M--) {
		scanf("%d %d", &d, &s);
		blizzard(d, s);

		if (linearBoard.empty()) {
			break;
		}
		// 구슬이 하나도 없는 경우 종료

		explosion();
		create();
		reset_board();

	}

	printf("%d", poped[1] + poped[2] * 2 + poped[3] * 3);
}

int main() {
	input();
	solution();

	return 0;
}
