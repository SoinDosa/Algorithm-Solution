#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int X[1000001];
vector<int> tmp, uniq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i];
		tmp.push_back(X[i]);
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || tmp[i - 1] != tmp[i])
		{
			uniq.push_back(tmp[i]);
		}
	}
	// �ߺ����ڸ� ������ �迭�� ���� �����

	for (int i = 0; i < N; ++i)
	{
		cout << lower_bound(uniq.begin(), uniq.end(), X[i]) - uniq.begin() << ' ';
	}
	// uniq �迭���� X[i]�� lower_bound ��ġ�� ���

	return 0;
}
// ������ ���� ���� ��ִ°�? ���� ����
// uniq.erase(unique(uni.begin(), uni.end()), uni.end());
// STL�� ����� �ߺ��� �����ϴ� ����� ����