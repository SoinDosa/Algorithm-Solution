#include <iostream>
#include <algorithm>

using namespace std;

int arr[500001];
int N;

int lowerIdx(const int& target, const int& len)
{
	int st = 0;
	int en = len;

	while (st < en)
	{
		int mid = (st + en) / 2;
		
		if (arr[mid] >= target)
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
	}

	return st;
}
// arr[mid] < target�� �� st = mid + 1

int upperIdx(const int& target, const int& len)
{
	int st = 0;
	int en = len;

	while (st < en)
	{
		int mid = (st + en) / 2;

		if (arr[mid] > target)
		{
			en = mid;
		}
		else
		{
			st = mid + 1;
		}
	}

	return st;
}
// lower�� upper�� ���̴� arr[mid]�� target�� ���� ��츦 �����ϴ��� ���ϴ��� ����
// ���� ������ ��ġ�� target���� ū ���� ���ʷ� ���;��ϴ� ��ġ�̱� ����

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	cin >> M;
	while (M--)
	{
		int input = 0;

		cin >> input;
		cout << upperIdx(input, N) - lowerIdx(input, N) << ' ';
	}

	return 0;
}