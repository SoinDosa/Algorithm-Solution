// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/0a12eb4ae44a4d86960f1e5c45eb6fca
#include <iostream>

using namespace std;

const int MAX = 1024 * 3 + 1;
// N(높이)의 최대값
char board[MAX][MAX * 2 - 1];
// (높이 * 2 - 1)은 밑변의 길이 

void fillStar(const int& x, const int& y)
{
	board[x][y] = '*';
	board[x + 1][y - 1] = '*';
	board[x + 1][y + 1] = '*';
	for (int i = y - 2; i <= y + 2; ++i)
	{
		board[x + 2][i] = '*';
	}
}

void func(const int& x, const int& y, const int& height)
{
	if (height == 3)
	{
		fillStar(x, y);
		return;
	}

	int n = height / 2;

	func(x, y, n);
	func(x + n, y - n, n);
	func(x + n, y + n, n);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	func(0, N - 1, N);
	// 최상단 꼭짓점부터 시작
	// 꼭짓점부터 시작하고 3개의 단위로 분할됨

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N * 2 - 1; ++j)
		{
			if (board[i][j] == '*')
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
// 이펙티브 C++ : 함수 내에서 변화할 일이 없는 매개변수에는 const &를 들이대라