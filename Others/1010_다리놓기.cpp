#include <iostream>
using namespace std;

int N, M;

void input() {
	scanf("%d %d", &N, &M);
}

void solution() {
	long long result = 1;
	long long temp = 1;

	for (int i = M; i > M - N; --i) {
		result *= i;
		result /= temp;
		temp++;
	}
  // 조합 문제 mCn
	printf("%ld\n", result);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		input();
		solution();
	}

  return 0;
}
