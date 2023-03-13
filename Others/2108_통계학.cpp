#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

static bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	vector<int> numbers;
	map<int, int> m;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int input;

		cin >> input;
		numbers.push_back(input);
		m[input]++;
	}
	sort(numbers.begin(), numbers.end());

	vector<pair<int, int>> numberCount(m.begin(), m.end());
	sort(numberCount.begin(), numberCount.end(), cmp);
	// ������ ������ ����ִ� map�� vector�� ��ȯ �� ���ؿ� �°� ����(���� ���� ��������, ���� ũ�� ��������)

	int total = 0;
	for (int number : numbers)
	{
		total += number;
	}

	int result = round((float)total / N);
	if (result == -0)
	{
		result = 0;
	}
	cout << result << '\n';
	// ������ ���

	cout << numbers[N / 2] << '\n';
	// �߾Ӱ� ���

	if (numberCount.size() >= 2 && numberCount[0].second == numberCount[1].second)
	{
		cout << numberCount[1].first << '\n';
	}
	else
	{
		cout << numberCount[0].first << '\n';
	}
	// �ֺ� ���

	cout << numbers[N - 1] - numbers[0];
	// ���� ���

	return 0;
}