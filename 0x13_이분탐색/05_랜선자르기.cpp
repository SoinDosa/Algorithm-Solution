#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int arr[10001];

bool isGetLan(const long long& x)
{
	long long cur = 0;
	for (int i = 0; i < K; ++i)
	{
		cur += arr[i] / x;
	}

	return cur >= N;
}
// ���� x�� �߶��� �� ���ϴ� ������ ������ ���� �� �ִ��� Ȯ��

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> K >> N;
	for (int i = 0; i < K; ++i)
	{
		cin >> arr[i];
	}

	long long st = 1;
	long long en = (1 << 31) - 1;
	// 2^31 - 1;

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;
		// (st + en) / 2�� �� ��� st�� en�� 1�� ���̳� �� st�� ��� ���� �Ȱ��ƹ��� �� ����

		if (isGetLan(mid) == true)
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
		// ���ϴ� ������ ������ �ȳ����� mid �̻��� ���� ���� �� �� �����Ƿ� en = mid - 1
	}
	cout << st;

	return 0;
}