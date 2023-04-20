#include <iostream>

using namespace std;

int main()
{
	long long n;

	cin >> n;
	cout << n * 4;
	// 밑변 = 사각형의 개수, 윗변 총합 = 사각형의 개수, 양변 = 사각형의 개수 * 2
	// 즉 둘레는 사각형의 개수 * 4

	return 0;
}