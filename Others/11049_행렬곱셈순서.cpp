#include <iostream>
using namespace std;

const int INF = 0x7FFFFFFF;
int N;
int dp[501][501];
// dp[i][j] => i번부터 j번 행렬까지의 최소 연산 횟수
int matrix[501][2];

void solution() {
	for (int i = 1; i <= N - 1; ++i) {
		for (int j = 1; j <= N - i; ++j) {
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; ++k) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
				// j번째부터 k번째 행렬곱 횟수 + k+1번째부터 i+j번째 행렬곱 횟수 + 결과로 나온 두 행렬의 곱
				// 이 중 최소를 dp[j][i + j]에 대입한다
			}
		}
		// dp[1][2] ~ dp[1][N]
	}
	cout << dp[1][N];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> matrix[i][0] >> matrix[i][1];
	}
	solution();
}
