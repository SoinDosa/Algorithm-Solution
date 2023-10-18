#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, K;
vector<int> nums;

void input() {
	scanf("%d %d", &N, &K);
	int num;
	for (int i = 0; i < N; ++i) {
		scanf("%1d", &num);
		nums.push_back(num);
	}
}

void solution() {
	stack<int> st;

	for (int i = 0; i < N; ++i) {
		while (!st.empty() && K > 0 && st.top() < nums[i]) {
			st.pop();
			--K;
		}
		st.push(nums[i]);
	}
	// 스택의 top이 현재 숫자보다 클 때까지 pop, pop 하면서 숫자지우는 횟수 증가
	
	vector<int> result;
	while (!st.empty()) {
		if (K > 0) {
			st.pop();
			--K;
			continue;
		}
		// 오답정리 : K가 남아있는 경우에 뒤에 작은 숫자를 다 지울 것
		result.push_back(st.top());
		st.pop();
	}

	int len = result.size();
	for (int i = len - 1; i >= 0; --i) {
		printf("%d", result[i]);
	}
}
// 스택을 활용한 풀이

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solution();

	return 0;
}
