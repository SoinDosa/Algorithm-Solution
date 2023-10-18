#include <iostream>
using namespace std;

int people[10][2];
int maxPeople;

void solution() {
	int curPeople = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> people[i][0] >> people[i][1];
		curPeople = curPeople - people[i][0] + people[i][1];
		maxPeople = max(maxPeople, curPeople);
	}
	cout << maxPeople;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solution();

	return 0;
}
