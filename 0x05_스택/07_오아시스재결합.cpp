// Authored by : haneulkimdev
// Co-authored by : -
// Commented by : Soindosa
// http://boj.kr/cbef82389d1048db80c9652d18b71304
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	stack<pair<int, int>> st;
	// first�� ����� Ű, second�� ���� Ű�� ���� ����� ����
	long long result = 0;
	// long long�� ���� : N��° ����� 500000 - N ���� ���� ������ ���
	// 499999 + 499998 + ... + 2 + 1 = 500000 * 250000 = 1250��

	cin >> N;
	while (N--)
	{
		int height;
		int count = 1;

		cin >> height;
		// height�� ���� ����� Ű, st�� �� �տ� �ִ� ����� �ǹ�
		while (!st.empty() && st.top().first <= height)
		{
			result += st.top().second;
			if (st.top().first == height)
			{
				count += st.top().second;
			}
			// Ű�� ���� ��� �ش� Ű�� ���� ����� count�� �ø���
			st.pop();
		}
		// ���� ����� Ű���� ���� ������� pop�ϰ� �ο�����ŭ result�� �ø���
		// ���̿� �� Ű�� ���� ����� �� �������� �ڿ������� st���� ������

		if (!st.empty())
		{
			result++;
		}
		// st�� ������� �ʴ� == ���� ����� st �ֻ�ܿ� �ִ� ��� �Ѹ� �� �� �ִ�
		
		st.push({ height, count });
	}

	cout << result;

	return 0;
}