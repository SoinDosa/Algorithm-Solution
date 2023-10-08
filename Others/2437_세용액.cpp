#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> requids;

void input() {
	scanf("%d", &N);
	long long val;
	for (int i = 0; i < N; ++i) {
		scanf("%ld", &val);
		requids.push_back(val);
	}
	sort(requids.begin(), requids.end());
}

void solution() {
	int best[3] = {};
	long long minSum = 0x7FFFFFFFFFFFFFF;

	for (int i = 0; i < N; ++i) {
		int st = 0;
		int en = N - 1;

		while (st < en) {
			if (st == i) {
				st++;
				continue;
			}
			else if (en == i) {
				en--;
				continue;
			}

			long long total = requids[i] + requids[st] + requids[en];
			if (abs(total) < minSum) {
				minSum = abs(total);
				best[0] = i;
				best[1] = st;
				best[2] = en;
			}

			if (total < 0) {
				st++;
			}
			else if (total > 0) {
				en--;
			}
			else {
				break;
			}
		}
	}

	sort(best, best + 3);
	printf("%ld %ld %ld", requids[best[0]], requids[best[1]], requids[best[2]]);
}

int main() {
	input();
	solution();

	return 0;
}
