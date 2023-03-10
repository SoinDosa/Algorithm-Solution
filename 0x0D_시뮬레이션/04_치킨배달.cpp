#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
int village[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int minChickenDist = 0x7FFFFFFF;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> village[i][j];
			if (village[i][j] == 1)
			{
				house.push_back({ i, j });
			}
			else if (village[i][j] == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + M, 0);
	// next_permutation ����� ���� vector
	// ġŲ���� ������ �������� ������ ġŲ�Ÿ��� �پ��Ƿ� ������ �ִ� ������ M���� �츰��
	do
	{
		int dist = 0;

		for (auto h : house)
		{
			int tmp = 0x7FFFFFFF;
			for (int i = 0; i < chicken.size(); ++i)
			{
				if (brute[i] == 1)
				{
					continue;
				}
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
			// �ּ� ġŲ�Ÿ� = �� ���� ġŲ�Ÿ�
		}
		minChickenDist = min(minChickenDist, dist);
		// �ּ� ġŲ�Ÿ� ����
	} while (next_permutation(brute.begin(), brute.end()));

	cout << minChickenDist;

	return 0;
}