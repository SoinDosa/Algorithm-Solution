#include <iostream>
using namespace std;

int s, N, K, R1, R2, C1, C2;

int func(int len, int x, int y)
{
	if (len == 1)
	{
		return 0;
	}

	int border = len / N;

	if (x >= border * (N - K) / 2 && x < border * (N + K) / 2 && y >= border * (N - K) / 2 && y < border * (N + K) / 2)
	{
		return 1;
	}
	// 한 변의 길이가 l인 평면의 가운데 k * k 영역에 속해있을 경우 검정색

	return func(border, x % border, y % border);
}
// len에는 전체 평면의 가로 길이가 저장됨

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

	int len = 1;
	while (s--)
	{
		len *= N;
	}

	for (int i = R1; i <= R2; ++i)
	{
		for (int j = C1; j <= C2; ++j)
		{
			cout << func(len, i, j);
		}
		cout << '\n';
	}
}
// n과 s를 이용하여 미리 전체 평면의 한 변의 길이를 구하고
// 이중 for문을 이용하여 행 r1, r2, 열 c1, c2 범위의 점들을 하나씩 판정하여 출력
