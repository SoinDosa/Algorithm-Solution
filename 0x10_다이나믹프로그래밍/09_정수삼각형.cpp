#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> triangle[501];
// [501][501] 2���� �迭�� ��� : �޸� 3000KB, �ð� 12ms
// vector<int> [501] ���� �迭�� ��� : �޸� 2692KB, �ð� 16ms

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			int input = 0;

			cin >> input;
			triangle[i].push_back(input);
		}
	}
	
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			if (j == 0)
			{
				triangle[i][j] += triangle[i - 1][j];
			}
			else if (j == i)
			{
				triangle[i][j] += triangle[i - 1][j - 1];
			}
			else
			{
				triangle[i][j] = max(triangle[i][j] + triangle[i - 1][j - 1], triangle[i][j] + triangle[i - 1][j]);
			}
		}
	}

	cout << *max_element(triangle[n - 1].begin(), triangle[n - 1].end());

	return 0;
}