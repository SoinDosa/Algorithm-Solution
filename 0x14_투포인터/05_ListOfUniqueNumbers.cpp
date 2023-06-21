// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<bool> chk(100'001);
	// �ش� ���� ������ �����ϴ��� üũ
	vector<int> numbers(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}

	long long cnt = 0;
	int en = 0;
	chk[numbers[0]] = true;

	for (int st = 0; st < N; ++st)
	{
		while (en < N - 1 && !chk[numbers[en + 1]])
		{
			chk[numbers[++en]] = true;
		}
		// en���� numbers[st] ~ numbers[en]�� ���� ���� �������� �ʴ� ���� ū �ε����� ��
		cnt += (en - st + 1);
		// ���ӵ� ��ȣ�� �����̹Ƿ� ���κ� �ε��� - ���� �ε��� + 1 = ������ ������
		chk[numbers[st]] = false;
	}

	cout << cnt;

	return 0;
}
// �������� : ������ �� ��������
// �ߺ����� ���� ���ӵ� ������ ������ �ƴ϶� ���� ���� ���� �� �������� �ʴ� �����̾���