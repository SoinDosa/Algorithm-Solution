// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/d98aedfde0e444509de83f1a21c8ef7e
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int n = 0;

		cin >> n;
		if (n == 0)
		{
			break;
		}

		stack <pair<long long, int>> st;
		// ������׷��� <����, �ε���>�� �����ϴ� ����
		long long result = 0;
		// height�� �ִ밡 10���̹Ƿ� �翬�� long long

		for (int i = 0; i < n; ++i)
		{
			long long h = 0;
			int index = i;
			// ���� �Է¹޴� �ε���

			cin >> h;
			while (!st.empty() && st.top().first >= h)
			{
				result = max(result, (i - st.top().second) * st.top().first);
				index = st.top().second;
				// �ε����� �ٲٰ� �������ν� �ش� ���̰� ��� �ʺ����
				// �ݿ��������� �ľ���
				// ex) {1, 0}�� ���ÿ� ���� ���� 1�� 0�� �ε������� �����ϴٴ� ��
				st.pop();
			}
			// st���� ���� �Ǵ� ������ �ʺ� 1�� �� ����
			// �� �������� ū ������ ���簢�� �ʺ� 1���ذ��� result ����
			st.push({ h, index });
		}

		while (!st.empty())
		{
			result = max(result, (n - st.top().second) * st.top().first);
			st.pop();
		}
		// ������ �Էµ� ���̱��� �ݿ��Ͽ� �ִ� �ʺ� �ľ�

		cout << result << '\n';
	}
	// 0�� �Է¹ޱ� ������ ���ѷ���

	return 0;
}