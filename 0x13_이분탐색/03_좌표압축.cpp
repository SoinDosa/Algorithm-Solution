#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int X[1000001];
vector<int> tmp, uniq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i];
		tmp.push_back(X[i]);
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < N; ++i)
	{
		if (i == 0 || tmp[i - 1] != tmp[i])
		{
			uniq.push_back(tmp[i]);
		}
	}
	// 중복숫자를 제거한 배열을 세로 만든다

	for (int i = 0; i < N; ++i)
	{
		cout << lower_bound(uniq.begin(), uniq.end(), X[i]) - uniq.begin() << ' ';
	}
	// uniq 배열에서 X[i]의 lower_bound 위치를 출력

	return 0;
}
// 나보다 작은 수가 몇개있는가? 묻는 문제
// uniq.erase(unique(uni.begin(), uni.end()), uni.end());
// STL을 사용해 중복을 제거하는 방법도 있음