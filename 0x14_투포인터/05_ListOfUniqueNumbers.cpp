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
	// 해당 수가 수열에 존재하는지 체크
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
		// en에는 numbers[st] ~ numbers[en]에 같은 수가 등장하지 않는 가장 큰 인덱스의 값
		cnt += (en - st + 1);
		// 연속된 번호의 수열이므로 끝부분 인덱스 - 시작 인덱스 + 1 = 수열의 갯수임
		chk[numbers[st]] = false;
	}

	cout << cnt;

	return 0;
}
// 오답정리 : 문제를 잘 못이해함
// 중복되지 않은 연속된 수열의 갯수가 아니라 같은 수가 여러 번 등장하지 않는 수열이었음