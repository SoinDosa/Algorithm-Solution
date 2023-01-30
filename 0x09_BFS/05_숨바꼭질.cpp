#include <iostream>
#include <queue>

using namespace std;

int subin[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int K = 0;
	queue<int> q;

	cin >> N >> K;
	subin[N] = 1;
	q.push(N);

	while (subin[K] == 0)
	{
		int cur = q.front();
		q.pop();

		for (int curX : { cur - 1, cur + 1, cur * 2})
		{
			if (curX < 0 || curX > 100000)
			{
				continue;
			}

			if (subin[curX] != 0)
			{
				continue;
			}

			subin[curX] = subin[cur] + 1;
			q.push(curX);
		}
		// 반복자 기반 반복문을 사용하는 방법, 성능상 차이는 크지 않음
	}
	// 오답노트
	// while 탈출 조건을 !q.empty()로 설정할 경우 이전 값이 덮어씌워지면서 실패한다

	cout << subin[K] - 1;

	return 0;
}