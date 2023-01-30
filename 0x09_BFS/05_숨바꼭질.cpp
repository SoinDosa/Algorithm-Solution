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
		// �ݺ��� ��� �ݺ����� ����ϴ� ���, ���ɻ� ���̴� ũ�� ����
	}
	// �����Ʈ
	// while Ż�� ������ !q.empty()�� ������ ��� ���� ���� ��������鼭 �����Ѵ�

	cout << subin[K] - 1;

	return 0;
}