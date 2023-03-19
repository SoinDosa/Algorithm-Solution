#include <iostream>
#include <queue>

using namespace std;

int n;
int w;
int L;
int bridge[101];
int totalWeight;
queue<int> trucks;

bool isBridgeEmpty()
{
	for (int w : bridge)
	{
		if (w != 0)
		{
			return false;
		}
	}

	return true;
}
void mv()
{
	for (int i = w - 1; i > 0; --i)
	{
		bridge[i] = bridge[i - 1];
	}
	bridge[0] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int totalTime = 0;

	cin >> n >> w >> L;
	while (n--)
	{
		int weight = 0;
		
		cin >> weight;
		trucks.push(weight);
	}

	do {
		if (totalWeight <= L)
		{
			totalWeight -= bridge[w - 1];
			// 나갈 트럭의 무게를 제외
			mv();
			// 단위시간만큼 트럭 이동
			if (!trucks.empty() && totalWeight + trucks.front() <= L)
			{
				bridge[0] = trucks.front();
				totalWeight += trucks.front();
				trucks.pop();
			}
			// 추가로 이동할 트럭이 있고 다리가 무게를 버틸 수 있으면 추가
			++totalTime;
		}
	} while (!isBridgeEmpty());
	// 다리가 전부 비어있을 때까지 실행

	cout << totalTime;

	return 0;
}