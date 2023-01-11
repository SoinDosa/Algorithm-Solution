#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// 이거 안넣으면 시간초과
	// 시간제한이 빡빡한 문제는 무조건 넣도록하자

	int N = 0;
	stack<pair<int, int>> tower;

	cin >> N;
	tower.push({ 100000001, 0 });
	for (int i = 1; i <= N; ++i)
	{
		int height = 0;
		cin >> height;
		while (tower.top().first < height)
		{
			tower.pop();
		}
		// 입력된 높이보다 큰 높이의 타워가 스택의 top에 남게 됨
		cout << tower.top().second << ' ';
		// 입력된 높이보다 큰 타워의 인덱스 출력

		tower.push({ height, i });
		// 입력된 타워와 인덱스를 스택에 push
	}

	return 0;
}
// O(N^2)은 시간초과