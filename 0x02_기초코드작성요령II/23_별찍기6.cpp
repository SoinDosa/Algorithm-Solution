#include <iostream>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;
	for (int i = N; i >= 1; --i) // 별찍기 같은 문제는 i의 시작점과 끝을 바꿔주는 방식으로 해결 가능
	{
		for (int j = 0; j < N - i; ++j)
		{
			cout << ' ';
		}

		for (int j = 0; j < 2 * i - 1; ++j)
		{
			cout << '*';
		}

		cout << '\n';
	}

	return 0;
}