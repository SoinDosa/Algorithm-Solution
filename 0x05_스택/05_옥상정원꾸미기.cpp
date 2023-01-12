// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/a84f083cdee3436f9f46acdef175e55f

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	stack<int> st;
	long long height = 0;
	long long result = 0;
	// result가 long long 이어야하는 이유
	// 최악의 경우 N 번 건물이 80000 - N개의 옥상을 벤치마킹할 수 있음, 79999 + 79998 ... + 2 + 1
	// 대략 80000 * 40000 = 32000000000(32억)

	cin >> N;
	while (N--)
	{
		cin >> height;
		while (!st.empty() && st.top() <= height)
		{
			st.pop();
		}
		// 이전 번호의 건물은 현재 번호의 건물옥상을 보지못함을 의미
		result += st.size();
		// st.size는 현재 빌딩옥상을 볼 수 있는 빌딩들의 갯수를 의미
		st.push(height);
	}
	// 빌딩 번호마다 볼 수 있는 건물의 개수가 아닌 현재 빌딩을 관찰할 수 있는 빌딩의 갯수에 중점을 둔 풀이법

	cout << result;

	return 0;
}