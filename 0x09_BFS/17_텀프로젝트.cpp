// Authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/65dc47124e3c4f53a9e5e710e78fa881
#include <iostream>

using namespace std;

int students[100001];
int state[100001];
// 0은 방문안함, -1은 누군가와 묶였음을 의미

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
		// cur 번호의 학생이 결국 i번째 학생과 이어짐
		else if (state[cur] != 0)
		{
			return;
		}
		// cur 번호의 학생으로 다시 돌아왔음을 의미, 묶이지 않음
		// 그 외에는 반복
	}
	// i 번호의 학생과 묶인 학생의 state를 모두 -1로 바꿈
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
		// 모든 학생의 상태를 방문안함으로 초기화

		for (int i = 1; i <= n; ++i)
		{
			if (state[i] == 0)
			{
				run(i);
			}
			// i 번호의 학생이 누군가와 아직 묶여있지 않다면 run 수행
		}

		for (int i = 1; i <= n; ++i)
		{
			if (state[i] != -1)
			{
				result++;
			}
		}
		// 묶여있지 않은 학생들의 수를 카운트

		cout << result << '\n';
	}
}