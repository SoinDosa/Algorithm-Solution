#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist[11][11];
vector<int> comb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		if (i != K)
		{
			comb.push_back(i);
		}
	}
	// ���������� ������ ��� �༺�� ��ȣ�� ������ �ִ´�

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> dist[i][j];
		}
	}

	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	// �÷��̵� �˰������� ��� �༺���� ��� �༺������ �ִܰŸ� ���

	int minTime = 0x7FFFFFFF;
	do
	{
		int tmp = dist[K][comb[0]];
		// �� ����� ���� �� ����ð�
		for (int i = 1; i < N - 1; ++i)
		{
			tmp += dist[comb[i - 1]][comb[i]];
		}
		minTime = min(minTime, tmp);
	} while (next_permutation(comb.begin(), comb.end()));
	// �༺�� �������� ��� ����� ���� ������ Ž��
	// ���������� �����Ǿ� �ִ�

	cout << minTime;

	return 0;
}
// ��������
// ��� �Ÿ��� �÷��̵�� ���ϰ� �༺���� �ּҰŸ��� �����ϴ� ����� Ʋ��