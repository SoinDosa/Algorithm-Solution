#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const string& a, const string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	vector<string> v;

	cin >> N;
	while (N--)
	{
		string input;

		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end(), cmp);

	string tmp;
	// find()를 사용하는 것보다 이전 문자열과 중복하는 것은 출력하지 않는게 더 빠르다
	for (auto str : v)
	{
		if (tmp != str)
		{
			cout << str << '\n';
		}
		tmp = str;
	}

	return 0;
}