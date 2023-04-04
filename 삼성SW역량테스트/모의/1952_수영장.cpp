#include<iostream>

using namespace std;

int price[4];
int plan[13];
int minCost = 1300000;
// 최대가격은 3000 * 30 * 12 = 1280000

void dfs(const int& month, const int& cost)
{
	if (month >= 12)
	{
		minCost = min(minCost, cost);
		return;
	}
	// 12월이 넘어가면 최소가격을 갱신하고 탈출

	if (plan[month + 1] == 0)
	{
		dfs(month + 1, cost);
	}
	// 다음 달에 계획이 없다면 cost 추가 없이 진행
	else
	{
		dfs(month + 1, cost + plan[month + 1] * price[0]);
		dfs(month + 1, cost + price[1]);
		dfs(month + 3, cost + price[2]);
	}
	// 1일, 1달, 3달 비용을 추가하며 나아감
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		for (int i = 0; i < 4; ++i)
		{
			cin >> price[i];
		}
		for (int i = 1; i <= 12; ++i)
		{
			cin >> plan[i];
		}
		minCost = price[3];
		// 1년치 금액과 비교

		dfs(0, 0);
		cout << '#' << test_case << ' ' << minCost << '\n';

		minCost = 1300000;
		// 최소값 초기화
	}
	return 0;
}