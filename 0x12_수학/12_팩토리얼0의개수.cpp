#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int cnt = 0;

	cin >> N;
	for (int i = 5; i <= N; i *= 5)
	{
		cnt += N / i;
	}
	// 500!은 매우 크기 때문에 어떤 자료형을 써도 불가능
	// 뒤에 0이 나오는 경우는 10이 곱해진 경우, 10 = 2 * 5이므로 N!을 소인수분해 했을 때 나오는 2와 5의 개수중 더 적은 수임
	// 하지만 5의 개수가 항상 더 적으므로 5의 개수만 구하면 됨
	// 인수가 5로 들어가는 것을 발견하면 +1, 5*5인 것은 +2...

	cout << cnt;

	return 0;
}
