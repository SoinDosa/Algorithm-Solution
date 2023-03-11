#include <iostream>
#include <algorithm>

using namespace std;

int rope[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int maxWeight = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> rope[i];
	}
	sort(rope, rope + N, greater<int>());
	// ������ ���� ������� ����

	for (int i = 0; i < N; ++i)
	{
		maxWeight = max(maxWeight, rope[i] * (i + 1));
	}
	// ���� ������� ��ƿ �� �ִ� ���Ը� �÷����� üũ
	// �ִ� �߷��� ���Ϸ��� ���� ������ �ʿ� ���� ������, ���� ���� ������ ����� �ʼ��̴�

	cout << maxWeight;

	return 0;
}