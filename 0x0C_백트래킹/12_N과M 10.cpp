// Authored by : connieya
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/7c17e31c609d4010ad339cec1f7ed280
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int input[10];
int arr[10];

void func(const int& cur, const int& index)
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

	for (int i = index; i < N; ++i)
	{
		if (tmp != input[i])
		{
			arr[cur] = input[i];
			tmp = arr[cur];
			func(cur + 1, i + 1);
		}
	}
}
// index변수를 통해 입력받은 수의 인덱스를 받고 다음 번호로 넘어감
// i가 input의 범위를 넘어간다고 해도 for문 조건문에서 걸러짐

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
	func(0, 0);

	return 0;
}