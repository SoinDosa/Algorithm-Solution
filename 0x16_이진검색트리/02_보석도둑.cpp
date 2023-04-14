#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


pair<int, int> jewels[300001];
// { V, M }
multiset<int> bags;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> jewels[i].second >> jewels[i].first;
	}
	sort(jewels, jewels + N);

	while (K--)
	{
		int C;

		cin >> C;
		bags.insert(C);
	}
	
	long long result = 0;

	for (int i = N - 1; i >= 0; --i)
	{
		multiset<int>::iterator it = bags.lower_bound(jewels[i].second);
		// ���� ��� i��° ������ ���Ը� ���� �� �ִ� ������ �ִ��� Ž��

		if (it == bags.end())
		{
			continue;
		}
		// �´� ������ ������ ���ٸ� ��ŵ
		result += jewels[i].first;
		bags.erase(it);
		// �ش� ������ ���Ǿ��� �ǹ��̹Ƿ� ����
	}

	cout << result;

	return 0;
}