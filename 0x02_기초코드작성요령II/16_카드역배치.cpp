#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int s = 0;
	int d = 0;

	for (int i = 0; i <= 20; ++i)
	{
		v.push_back(i);
	}

	for (int i = 0; i < 10; ++i)
	{
		cin >> s >> d;
		reverse(v.begin() + s, v.begin() + d + 1);
		// ����� ��ġ�� ������ �Լ��̸� algorithm ����� ���ǵ�
	}

	for (int i = 1; i <= 20; ++i)
	{
		cout << v[i] << ' ';
	}

	return 0;
}