// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
#include <iostream>
using namespace std;

int N, M;

pair<int, int> func(int side, int walk)
{
	if (side == 2)
	{
		switch (walk)
		{
		case 1:
			return { 1, 1 };
		case 2:
			return { 1, 2 };
		case 3:
			return { 2, 2 };
		case 4:
			return { 2, 1 };
		}
	}
	// base condition : 변의 길이가 2

	int half = side / 2;
	int oneSquare = half * half;

	if (walk > 3 * oneSquare)
	{
		pair<int, int> rv = func(half, walk - 3 * oneSquare);
		return { 2 * half - rv.second + 1, half - rv.first + 1 };
	}
	else if (walk > 2 * oneSquare)
	{
		pair<int, int> rv = func(half, walk - 2 * oneSquare);
		return { half + rv.first, half + rv.second };
	}
	else if (walk > oneSquare)
	{
		pair<int, int> rv = func(half, walk - oneSquare);
		return { rv.first, half + rv.second };
	}
	else
	{
		pair<int, int> rv = func(half, walk);
		return { rv.second, rv.first };
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	pair<int, int> result = func(N, M);
	cout << result.first << ' ' << result.second;
}
// 4개로 나눠 walk를 바탕으로 어느 사분면에 존재하는지 파악한 후
// 적절한 계상을 통해 사각형을 축소시키며 좌표값을 계산한다