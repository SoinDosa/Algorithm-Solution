#include <iostream>
#include <vector>
using namespace std;

vector<int> values;
int N;

void input() {
	scanf("%d", &N);

	int input;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &input);
		values.push_back(input);
	}
}

void solution() {
	int st = 0, en = N - 1;
	int minGap = 0x7FFFFFFF;
	int posA = st, posB = en;
	while (st < en) {
		int gap = values[en] + values[st];

		if (abs(gap) < minGap) {
			minGap = abs(gap);
			posA = st;
			posB = en;
		}

		if (gap == 0) {
			break;
		}
		else if (gap > 0) {
			--en;
		}
		else {
			++st;
		}
	}
	printf("%d %d", values[posA], values[posB]);
}

int main() {
	input();
	solution();

	return 0;
}
