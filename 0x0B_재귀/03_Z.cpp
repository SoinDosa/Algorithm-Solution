#include <iostream>

using namespace std;

int Z(int n, int r, int c)
{
	if (n == 0)
	{
		return 0;
	}

	int half = 1 << (n - 1);
	// 2^n-1

	if (r < half && c < half)
	{
		return Z(n - 1, r, c);
	}
	else if (r < half && c >= half)
	{
		return half * half + Z(n - 1, r, c - half);
	}
	else if (r >= half && c < half)
	{
		return 2 * half * half + Z(n - 1, r - half, c);
	}
	else
	{
		return 3 * half * half + Z(n - 1, r - half, c - half);
	}
	// 각각 1, 2, 3, 4 번 사각형임
	// 사각형 위치에 따라 r, c에서 half만큼을 빼줘서 값을 조정해줘야 정확하게 찾을 수 있다
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int r;
	int c;

	cin >> N >> r >> c;
	cout << Z(N, r, c);
}