#include <iostream>

using namespace std;

const long long INIT_MIN = 300000000000;
const long long INIT_MAX = -300000000000;

int N;
int op[4];
int arr[13];
long long minResult;
long long maxResult;

void dfs(const int& cur, const long long& val)
{
	if (cur >= N - 1)
	{
		maxResult = max(maxResult, val);
		minResult = min(minResult, val);

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		if (op[i] > 0)
		{
			op[i]--;
			switch (i)
			{
			case 0:
				dfs(cur + 1, val + arr[cur + 1]);
				break;
			case 1:
				dfs(cur + 1, val - arr[cur + 1]);
				break;
			case 2:
				dfs(cur + 1, val * arr[cur + 1]);
				break;
			case 3:
				dfs(cur + 1, val / arr[cur + 1]);
				break;
			}
			op[i]++;
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		maxResult = INIT_MAX;
		minResult = INIT_MIN;

		cin >> N;
		for (int i = 0; i < 4; ++i)
		{
			cin >> op[i];
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}

		dfs(0, arr[0]);

		cout << '#' << test_case << ' ' << maxResult - minResult << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}