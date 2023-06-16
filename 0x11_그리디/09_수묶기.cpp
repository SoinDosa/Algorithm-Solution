// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long result;

void seq_sum(vector<int>& v)
{
	while (v.size() > 1)
	{
		result += *(v.end() - 1) * *(v.end() - 2);
		v.pop_back();
		v.pop_back();
	}
	// ���밪�� ���� ū ������ ���ذ��� result�� ����

	if (v.size() > 0)
	{
		result += v[0];
	}
	// v�� ��Ұ� �ϳ��� ������ �� �׳� result�� ����
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> seqP, seqN;
	// ������ ����� ���ϸ� ������ ������ �����Ƿ� ������ ����� ���� ����
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;

		if (input == 1)
		{
			result++;
		}
		// 1�� ���ص� �״�ζ� ������ �����̹Ƿ� �׳� result�� ���Ѵ�
		else if (input > 0)
		{
			seqP.push_back(input);
		}
		else
		{
			seqN.push_back(input);
		}
		// 0�� seqN�� �ִ´�. ������ 0�� ���ؼ� 0�� �Ǹ� ������ �̵��̴�
	}
	sort(seqP.begin(), seqP.end());
	sort(seqN.begin(), seqN.end(), greater<>());
	// ���밪�� ���� ������� ����

	seq_sum(seqP);
	seq_sum(seqN);

	cout << result;

	return 0;
}