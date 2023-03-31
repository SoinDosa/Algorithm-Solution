// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/0d301f4f0b4e4beebc7889e220b0145f
#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long M = 0;
long long trees[1000001];

bool isEnough(const int& height)
{
	long long sum = 0;

	for (int i = 0; i < N; ++i)
	{
		if (trees[i] <= height)
		{
			continue;
		}
		sum += trees[i] - height;
	}
	return sum >= M;
}
// 나무들을 height만큼 자르면 충분한가?

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> trees[i];
	}

	int st = 0;
	int en = *max_element(trees, trees + N);
	// 최소 길이와 최대 길이

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;

		if (isEnough(mid) == true)
		{
			st = mid;
		}
		// mid만큼 잘랐을 때 충분하다면 mid를 시작지점으로 다시 탐색
		else
		{
			en = mid - 1;
		}
	}
	cout << st;

	return 0;
}