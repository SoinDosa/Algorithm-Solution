#include <iostream>
#include <vector>

using namespace std;

int N;
int maxCount;
vector<pair<int, int>> eggs;

int checkBrokeCount()
{
	int brokeCount = 0;

	for (int i = 0; i < N; ++i)
	{
		if (eggs[i].first <= 0)
		{
			brokeCount++;
		}
	}

	return brokeCount;
}

void func(const int& cur)
{
	int brokeCount = checkBrokeCount();

	if (cur == N)
	{
		maxCount = max(brokeCount, maxCount);

		return;
	}

	if (eggs[cur].first <= 0 || brokeCount == N - 1)
	{
		func(cur + 1);
		return;
	}
	// 선택한 계란이 깨져있거나 깨트릴 계란이 없을 경우 다음으로 넘어감

	for (int i = 0; i < N; ++i)
	{
		if (i == cur || eggs[i].first <= 0)
		{
			continue;
		}

		eggs[cur].first -= eggs[i].second;
		eggs[i].first -= eggs[cur].second;
		func(cur + 1);
		eggs[cur].first += eggs[i].second;
		eggs[i].first += eggs[cur].second;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int durablility = 0;
		int weight = 0;

		cin >> durablility >> weight;
		eggs.push_back({ durablility, weight });
	}

	func(0);
	cout << maxCount;

	return 0;
}