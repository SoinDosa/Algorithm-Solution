#include <iostream>

using namespace std;

int arr[10000001] = { 0, };
bool occur[2000000];

int main()
{
	// arr을 main 함수 내부에 넣으면 스택용량을 초과했다는 경고문이 출력된다
	// arr을 heap 영역으로 옮기거나 vector를 사용하면 문제 없다
	// 하지만 O(n^2)의 시간복잡도로 풀이하면 시간초과이다
	int n = 0;
	int x = 0;
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; ++i)
	{
		// x - arr[i]를 찾으면 true로 바꾼다. 이러면 맞는 순서쌍이 있을 때 해당 수의 occur이 true가 되면서 한쌍이 있다는 말이 된다
		// 공간복잡도 O(2000000), 시간복잡도 O(n)으로 풀 수 있는 방법이다
		if (x - arr[i] > 0 && occur[x - arr[i]])
		{
			result++;
		}
		occur[arr[i]] = true;
	}

	cout << result;

	return 0;
}