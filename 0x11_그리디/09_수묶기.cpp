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
	// 절대값이 가장 큰 값끼리 곱해가며 result에 더함

	if (v.size() > 0)
	{
		result += v[0];
	}
	// v의 요소가 하나만 남았을 땐 그냥 result에 더함
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> seqP, seqN;
	// 음수와 양수를 곱하면 무조건 음수가 나오므로 음수와 양수를 따로 보관
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
		// 1은 곱해도 그대로라 오히려 손해이므로 그냥 result에 더한다
		else if (input > 0)
		{
			seqP.push_back(input);
		}
		else
		{
			seqN.push_back(input);
		}
		// 0도 seqN에 넣는다. 음수에 0을 곱해서 0이 되면 오히려 이득이다
	}
	sort(seqP.begin(), seqP.end());
	sort(seqN.begin(), seqN.end(), greater<>());
	// 절대값이 작은 순서대로 정렬

	seq_sum(seqP);
	seq_sum(seqN);

	cout << result;

	return 0;
}