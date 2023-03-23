#include <iostream>
#include <algorithm>

using namespace std;

int times[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> times[i];
	}
	sort(times, times + N);

	int totalTime = 0;
	int sumTime = 0;
	for (int i = 0; i < N; ++i)
	{
		sumTime += times[i];
		totalTime += sumTime;
	}

	cout << totalTime;

	return 0;
}