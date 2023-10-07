#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> players;
bool isExist[1000001];
int score[1000001];

void input() {
	cin >> N;

	int number;
	for (int i = 0; i < N; ++i) {
		cin >> number;
		isExist[number] = true;
		players.push_back(number);
	}
}

void solution() {
	for (int card : players) {
		for (int j = card * 2; j <= 1000000; j += card) {
			if (isExist[j]) {
				score[card]++;
				score[j]--;
			}
		}
    // 에라토스테네스의 체 활용
    // 플레이어의 카드 배수가 존재하면 결투
    // 플레이어는 득점, 상대방은 감점
	}

	for (int card : players) {
		cout << score[card] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();

	return 0;
}
