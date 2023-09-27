#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int player[51][10];

void init() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 9; ++j) {
			cin >> player[i][j];
		}
	}
}

int calc_point(vector<int> playerOrder) {
	int turn = 0;
	int totalScore = 0;
	for (int i = 1; i <= N; ++i) {
		bool isOn[4] = { true, false, false, false };
		// 0루 == 홈
		int totalOut = 0;
		while (1) {
			if (turn >= 9) {
				turn = 0;
			}
			int curPlayer = playerOrder[turn++];
			int curShot = player[i][curPlayer];

			if (curShot == 0) {
				++totalOut;
			}

			if (totalOut >= 3) {
				break;
			}

			for (int i = 3; i >= 0; --i) {
				if (!isOn[i]) {
					continue;
				}
				int temp = i + curShot;
				isOn[i] = false;
				// i번 루에 있는 선수가 출루

				if (temp >= 4) {
					++totalScore;
				} // 홈인
				else {
					isOn[temp] = true;
				} // 해당 루에 자리잡음
			}
			isOn[0] = true;
			// 다음 타자가 홈에 들어옴
		}
	}
	return totalScore;
}

void solution() {
	int playerNum[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	int maxScore = 0;
	do {
		vector<int> playerOrder;
		for (int i = 0; i < 3; ++i) {
			playerOrder.push_back(playerNum[i]);
		}
		playerOrder.push_back(1);
		for (int i = 3; i < 8; ++i) {
			playerOrder.push_back(playerNum[i]);
		}
		// 타석 순서를 정한다
		maxScore = max(maxScore, calc_point(playerOrder));
	} while (next_permutation(playerNum, playerNum + 8));

	cout << maxScore;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();
	solution();
}
