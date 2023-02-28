#include <iostream>

using namespace std;

int arr[21];
int N;
int S;
int cnt;

void func(const int& len, const int& total)
{
	if (len == N)
	{
		if (total == S)
		{
			cnt++;
		}
		return;
	}

	func(len + 1, total);
	func(len + 1, total + arr[len]);
	// 수열의 길이는 N과 같게 하고, arr에 해당하는 값을 더할지, 아니면 더하지 않을지 2가지 분기로 나누면서 상태공간트리 만들어나감
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> S;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	func(0, 0);
	if (S == 0)
	{
		cnt--;
	}
	// 크기가 양수인 부분수열만 센다고 했으니 공집합은 제외
	// S가 0일 경우에만 1을 빼주면 됨
	cout << cnt;

	return 0;
}