#include <iostream>

using namespace std;

int N;
int A[1000001];
int B, C;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long cnt = 0;
	// �������� : �� ������ ���� �ִ� ������ 1000000 * 1000000 �̹Ƿ� int ������ �ʰ���

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	cin >> B >> C;
	for (int i = 0; i < N; ++i)
	{
		A[i] -= B;
		cnt++;

		if (A[i] > 0)
		{
			cnt += A[i] / C;
			if ((A[i] % C) > 0)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}