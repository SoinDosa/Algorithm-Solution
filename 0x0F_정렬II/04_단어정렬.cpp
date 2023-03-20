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
	// find()�� ����ϴ� �ͺ��� ���� ���ڿ��� �ߺ��ϴ� ���� ������� �ʴ°� �� ������
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