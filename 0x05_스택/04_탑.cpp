#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	// �̰� �ȳ����� �ð��ʰ�
	// �ð������� ������ ������ ������ �ֵ�������

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
		// �Էµ� ���̺��� ū ������ Ÿ���� ������ top�� ���� ��
		cout << tower.top().second << ' ';
		// �Էµ� ���̺��� ū Ÿ���� �ε��� ���

		tower.push({ height, i });
		// �Էµ� Ÿ���� �ε����� ���ÿ� push
	}

	return 0;
}
// O(N^2)�� �ð��ʰ�