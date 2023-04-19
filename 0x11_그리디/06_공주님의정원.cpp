// Authored by : jihwan0123
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	vector<pair<int, int>> flowers;
	// { ���� �Ǵ� ��, ���� ���� �� }

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int startMon, startDay, endMon, endDay;

		cin >> startMon >> startDay >> endMon >> endDay;
		flowers.push_back({ startMon * 100 + startDay, endMon * 100 + endDay });
		// �̷��� �ϸ� 3�� 1���� 301, 11�� 30���� 1130 ������ ����
	}

	int t = 301;
	// ���۳�¥, 3�� 1��
	int result = 0;

	while (t < 1201)
	{
		int nxtT = t;

		for (int i = 0; i < N; ++i)
		{
			if (flowers[i].first <= t && flowers[i].second > nxtT)
			{
				nxtT = flowers[i].second;
			}
			// ��� �� ����Ʈ�� üũ�Ͽ� (���� ��¥���� �̸��ų� ���� ��¥�� �ǰ�, �ʰ� ���� ���� Ž��
		}

		if (nxtT == t)
		{
			cout << 0;
			return 0;
		}
		// ���� ��¥���� ������ �Ұ��� = �� ��¥�� ����, ���� �� ����

		result++;
		t = nxtT;
	}
	// end��¥�� 11�� 30���̸� 11�� 30�Ͽ� ���� �ɰ� �ƴϴ�, ��¥ 12�� 1�ϱ��� üũ

	cout << result;

	return 0;
}
/*
�켱 �׸����� �������� �����غ��� �Ź� ���� �������� �Ǿ��ִ� �� �߿���
���� �������� ���� ���� �����ϸ� �ȴ�.
3�� 1�Ͽ������� 11�� 30�ϱ����� �� 276���� �Ⱓ�̴� ��� ���� �Ϸ縸�� �Ǿ��ٰ�
���� �ص� �ִ� 276���� ���� �����ϱ⸸ �ϸ� �ȴ�. �׷��� ������ �׳� �Ź� O(N)���� 
���� �����ϸ� �ȴ�. �ð����⵵�� �־��� ��� O(276N)�̴�.
���� ������ 3�� 1�� to 11�� 30���� �ƴ϶� 1�Ͽ��� 1,000,000,000�� ���̿��� �ɵ���
���ؾ� �ϴ� �������ٸ� �Ź� O(N)���� ���� ���� Ž���ϴ� Ǯ�̴� �ִ� O(N^2)����
�ð��ʰ����ٵ� �� ��� ��� �ذ��ϸ� ������ ����غ��°� ��õ�Ѵ�.
by ��ŷ����
*/