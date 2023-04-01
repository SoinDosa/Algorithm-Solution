#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A = 0, B = 0, V = 0;

	cin >> A >> B >> V;

	long long height = V - A;
	long long oneDay = A - B;
	long long result = height / oneDay;

	if (height % oneDay != 0)
	{
		result++;
	}
	// 마지막 스퍼트를 제외하고 높이를 올라가야하는 날을 구함

	cout << result + 1;
	// 마지막날까지 포함
}