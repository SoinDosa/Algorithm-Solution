#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int U[1001];
vector<int> two;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> U[i];
	}
	sort(U, U + N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			two.push_back(U[i] + U[j]);
		}
	}
	// 2���� ���� ���� ��츦 two ���Ϳ� ����
	sort(two.begin(), two.end());
	// �̺�Ž���� ���� two ���͵� �����Ѵ�

	/*for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j < twoSize; ++j)
		{
			if (binary_search(U, U + N, U[i] - two[j]))
			{
				cout << U[i];

				return 0;
			}
		}
	}*/
	// ����
	// twoSize = N^2�̹Ƿ� �ð��ʰ� �߻�
	// �Ʒ�ó�� binary_sarch�� ���� 2logN���� �ٲ�����Ѵ�

	for (int i = N - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (binary_search(two.begin(), two.end(), U[i] - U[j]))
			{
				cout << U[i];
				return 0;
			}
		}
	}
	// ���� Ǯ�̴� N^3, �� Ǯ�̴� N^2logN
}