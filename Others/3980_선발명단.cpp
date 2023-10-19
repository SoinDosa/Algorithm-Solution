#include <iostream>
using namespace std;

int ovr[11][11];

int maxOvr;
bool isCallup[11];
int player[11];
// for backtracking

void input() {
	maxOvr = 0;
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 11; ++j) {
			scanf("%d", &ovr[i][j]);
		}
	}
}

void func(int cur) {
	if (cur == 11) {
		int totalOvr = 0;
		for (int i = 0; i < 11; ++i) {
			totalOvr += ovr[player[i]][i];
			// player[i] 번 선수가 i 포지션에서 뛸 때의 능력치
		}
		maxOvr = max(maxOvr, totalOvr);
		return;
	}

	for (int playerNumber = 0; playerNumber < 11; ++playerNumber) {
		if (isCallup[playerNumber]) {
			continue;
		}

		if (ovr[playerNumber][cur] == 0) {
			continue;
		}
		isCallup[playerNumber] = true;
		player[cur] = playerNumber;
		func(cur + 1);
		isCallup[playerNumber] = false;
	}
}

void solution() {
	func(0);
	printf("%d\n", maxOvr);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		input();
		solution();
	}
}
