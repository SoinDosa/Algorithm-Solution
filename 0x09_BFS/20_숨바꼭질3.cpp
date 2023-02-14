// Authored by : heheHwang
// Co-authored by : -
// Commented by : Soindosa
// http://boj.kr/39302be343944bda8d83b89a00b24759
#include <iostream>
#include <queue>

using namespace std;

int dist[100001];
int N;
int K;
queue<int> q;

void teleport(int num)
{
	int tmp = num;

	if (tmp == 0)
	{
		return;
	}

	while (tmp <= 100000 && dist[K] == 0)
	{
		if (dist[tmp] == 0)
		{
			dist[tmp] = dist[num];
			// �����̵��� �ð��� �Ҹ����� �ʴ´�
			q.push(tmp);

			if (tmp == K)
			{
				return;
			}
		}
		tmp <<= 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	dist[N] = 1;
	q.push(N);
	teleport(N);
	while (dist[K] == 0)
	{
		int cur = q.front();

		q.pop();
		for (int dir : {cur + 1, cur - 1})
		{
			if (dir < 0 || dir > 100000)
			{
				continue;
			}

			if (dist[dir] != 0)
			{
				continue;
			}

			dist[dir] = dist[cur] + 1;
			q.push(dir);
			teleport(dir);
			// teleport �Լ��� ���� �ش� ���� 2�� ������ġ�� ��� �ľ���
		}
	}

	cout << dist[K] - 1;

	return 0;
}