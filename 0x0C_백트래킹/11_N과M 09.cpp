// Authored by : connieya
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/8c038985c8d24ae2a79aa5288f5f4ee3
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int input[10];
int arr[10];
bool isUsed[10];

void func(const int& cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	int tmp = 0;
	// 중복 수열인지 확인하기 위해 필요한 임시 변수
	// 입력으로 주어지는 수는 자연수 이므로 0은 들어올 수 없음

	for (int i = 0; i < N; ++i)
	{
		if (isUsed[i] == false && tmp != input[i])
		{
			isUsed[i] = true;
			arr[cur] = input[i];
			tmp = arr[cur];
			// 현재 for문 안에서 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
			func(cur + 1);
			isUsed[i] = false;
		}
		// 즉 tmp는 이전 수열의 마지막 항, 현재 보는 수와 동일하면 func(cur + 1)을 실행시키지 않음
		// 같은 수만 입력받았다고 해도 새로운 func에서 tmp는 0으로 초기화되므로 문제 없음
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}
	sort(input, input + N);
	func(0);

	return 0;
}