#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<long long> snacks;

bool isEnough(const long long& length)
{
	int cnt = 0;

	for (int snack : snacks)
	{
		cnt += snack / length;

		if (cnt >= M)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> M >> N;
	while (N--)
	{
		long long input;
		cin >> input;

		snacks.push_back(input);
	}
	sort(snacks.begin(), snacks.end(), greater<>());

	long long st = 0;
	// ��� ��ī���� ���� ������ ������ڸ� ������ �� ���ٸ� 0�� ����ؾ���
	long long en = snacks[0];

	while (st < en)
	{
		long long mid = (st + en + 1) / 2;

		if (isEnough(mid))
		{
			st = mid;
		}
		else
		{
			en = mid - 1;
		}
	}
	cout << st;

	return 0;
}