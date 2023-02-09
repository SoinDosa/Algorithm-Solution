// Authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/65dc47124e3c4f53a9e5e710e78fa881
#include <iostream>

using namespace std;

int students[100001];
int state[100001];
// 0�� �湮����, -1�� �������� �������� �ǹ�

void run(int i)
{
	int cur = i;

	while (true)
	{
		state[cur] = i;
		cur = students[cur];

		if (state[cur] == i)
		{
			while (state[cur] != -1)
			{
				state[cur] = -1;
				cur = students[cur];
			}
			return;
		}
		// cur ��ȣ�� �л��� �ᱹ i��° �л��� �̾���
		else if (state[cur] != 0)
		{
			return;
		}
		// cur ��ȣ�� �л����� �ٽ� ���ƿ����� �ǹ�, ������ ����
		// �� �ܿ��� �ݺ�
	}
	// i ��ȣ�� �л��� ���� �л��� state�� ��� -1�� �ٲ�
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;
	
	cin >> T;
	while (T--)
	{
		int n = 0;
		int result = 0;

		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> students[i];
		}
		fill(state + 1, state + 1 + n, 0);
		// ��� �л��� ���¸� �湮�������� �ʱ�ȭ

		for (int i = 1; i <= n; ++i)
		{
			if (state[i] == 0)
			{
				run(i);
			}
			// i ��ȣ�� �л��� �������� ���� �������� �ʴٸ� run ����
		}

		for (int i = 1; i <= n; ++i)
		{
			if (state[i] != -1)
			{
				result++;
			}
		}
		// �������� ���� �л����� ���� ī��Ʈ

		cout << result << '\n';
	}
}