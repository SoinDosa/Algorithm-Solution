#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	// �Է��� ���ڸ� ������������ ����

	int cnt = 0;
	// ���� ���� �ִ� ���ڰ� �����ؼ� ��� ���Դ°�?
	long long maxVal = -(1 << 62);
	// ���� ���� ��, �ּ� ������ -2^62�� ����
	int maxCnt = 0;
	// ���� ���� ���ӵ� Ƚ��
	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || arr[i - 1] == arr[i])
		{
			cnt++;
		}
		else
		{
			if (cnt > maxCnt)
			{
				maxCnt = cnt;
				maxVal = arr[i - 1];
			}
			cnt = 1;
		}
		// ������ ����� cnt�� maxCnt���� ũ�ٸ� maxCnt, maxVal�� ����
		// >= �� �ƴϰ� > �̹Ƿ� ������ ������ ū ���ڷ� ���ŵ��� ����
	}
	if (cnt > maxCnt)
	{
		maxVal = arr[N - 1];
	}
	// ���� ������ ���� �� �� �����ߴ����� ������ Ȯ��

	cout << maxVal;

	return 0;
}