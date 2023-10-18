#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int boardSize[2];
// 0 : 세로 길이, 1 : 가로길이
vector<int> cutPos[2];
// 0 : 가로, 1 : 세로
vector<int> cutSize[2];

void input() {
	int K;
	cin >> boardSize[1] >> boardSize[0] >> K;
	
	int idx, num;
	while (K--) {
		cin >> idx >> num;
		cutPos[idx].push_back(num);
	}
	
	for (int i = 0; i < 2; ++i) {
		sort(cutPos[i].begin(), cutPos[i].end());
	}
}

void solution() {
	for (int i = 0; i < 2; ++i) {
		int prevPos = 0;
		for (int pos : cutPos[i]) {
			cutSize[i].push_back(pos - prevPos);
			prevPos = pos;
		}
		cutSize[i].push_back(boardSize[i] - prevPos);
	}

	int maxSize = 0;
	for (int i = 0; i < cutSize[0].size(); ++i) {
		for (int j = 0; j < cutSize[1].size(); ++j) {
			maxSize = max(maxSize, cutSize[0][i] * cutSize[1][j]);
		}
	}

	cout << maxSize;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();

	return 0;
}
