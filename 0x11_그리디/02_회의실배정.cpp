#include <iostream>
#include <algorithm>

using namespace std;
pair<int, int> meetings[1000001];
// { end time, st time };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> meetings[i].second >> meetings[i].first;
	}
	sort(meetings, meetings + N);
	// �Է¹��� ȸ�Ǹ� ���� ������ ������, ������ �ð��� ���ٸ� ���� �����ϴ� ������ �����Ѵ�

	int result = 0;
	int t = 0;

	for (int i = 0; i < N; ++i)
	{
		if (t > meetings[i].second)
		{
			continue;
		}
		// ������ �ð����� ���� �ð��� ���� ȸ�Ǵ� �н�
		result++;
		t = meetings[i].first;
		// ���� ȸ�ǵ� �� ������ �ð��� ���� ���� ȸ�Ǹ� �ִ´�
	}

	cout << result;

	return 0;
}