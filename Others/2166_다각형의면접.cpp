#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
	scanf("%d", &N);

	vector<pair<int, int>> coords;
	for (int i = 0; i < N; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		coords.push_back({ x, y });
	}

	long long sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum += 1LL * coords[i].first * coords[i + 1].second - 1LL * coords[i].second * coords[i + 1].first;
	}
	sum += 1LL * coords[N - 1].first * coords[0].second - 1LL * coords[0].first * coords[N - 1].second;
	// 마지막을 더해주는 것에 주의
	if (sum < 0) {
		sum = -sum;
	}

	double ans = sum / 2.0;
	printf("%.1lf", ans);

	return 0;
}
// CCW 알고리즘 문제
// 여러 개의 점에서 x1y2 + x2y3 ... + xn-1yn + xny0 - y1x2 - y2x3 ... -yn-1xn - ynx0 을 구한다
// => 평행사변형의 넓이가 나온다
