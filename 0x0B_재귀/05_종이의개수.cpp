// Authored by : cpprhtn
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/b8488e82105d49e89ca6f39fd8ee665b
#include <iostream>

using namespace std;

int N;
int paper[2200][2200];
int cnt[3];

bool isSamePaper(int x, int y, int n)
{
	for (int i = x; i < x + n; ++i)
	{
		for (int j = y; j < y + n; ++j)
		{
			if (paper[x][y] != paper[i][j])
			{
				return false;
				// n * n 종이의 색깔이 하나라도 다르다면 false 
			}
		}
	}
	return true;
}
// 해당 종이 내부가 같은 숫자로만 채워져 있는지 확인
// n은 종이의 변의 길이

void func(int x, int y, int z)
{
	if (isSamePaper(x, y, z))
	{
		cnt[paper[x][y] + 1]++;
		return;
	}

	int n = z / 3;
	// 변의 길이를 1/3으로 만듬

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			func(x + i * n, y + j * n, n);
			// 총 9개로 분할하여 func 재수행
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> paper[i][j];
		}
	}
	
	func(0, 0, N);

	for (int i = 0; i < 3; ++i)
	{
		cout << cnt[i] << '\n';
	}

	return 0;
}