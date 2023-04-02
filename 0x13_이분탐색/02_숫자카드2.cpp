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
// arr[mid] < target일 때 st = mid + 1

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
// lower와 upper의 차이는 arr[mid]가 target과 같은 경우를 포함하느냐 안하느냐 차이
// 가장 오른쪽 위치는 target보다 큰 수가 최초로 나와야하는 위치이기 때문

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