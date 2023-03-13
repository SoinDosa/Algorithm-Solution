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
	// 숫자의 갯수가 들어있는 map을 vector로 변환 후 기준에 맞게 정렬(숫자 개수 내림차순, 숫자 크기 내림차순)

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
	// 산술평균 출력

	cout << numbers[N / 2] << '\n';
	// 중앙값 출력

	if (numberCount.size() >= 2 && numberCount[0].second == numberCount[1].second)
	{
		cout << numberCount[1].first << '\n';
	}
	else
	{
		cout << numberCount[0].first << '\n';
	}
	// 최빈값 출력

	cout << numbers[N - 1] - numbers[0];
	// 범위 출력

	return 0;
}