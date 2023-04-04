#include<iostream>

using namespace std;

int price[4];
int plan[13];
int minCost = 1300000;
// �ִ밡���� 3000 * 30 * 12 = 1280000

void dfs(const int& month, const int& cost)
{
	if (month >= 12)
	{
		minCost = min(minCost, cost);
		return;
	}
	// 12���� �Ѿ�� �ּҰ����� �����ϰ� Ż��

	if (plan[month + 1] == 0)
	{
		dfs(month + 1, cost);
	}
	// ���� �޿� ��ȹ�� ���ٸ� cost �߰� ���� ����
	else
	{
		dfs(month + 1, cost + plan[month + 1] * price[0]);
		dfs(month + 1, cost + price[1]);
		dfs(month + 3, cost + price[2]);
	}
	// 1��, 1��, 3�� ����� �߰��ϸ� ���ư�
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
		// 1��ġ �ݾװ� ��

		dfs(0, 0);
		cout << '#' << test_case << ' ' << minCost << '\n';

		minCost = 1300000;
		// �ּҰ� �ʱ�ȭ
	}
	return 0;
}