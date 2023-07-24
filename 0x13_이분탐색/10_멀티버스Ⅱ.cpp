// Authored by : SciEm
// Commented by : Soindosa
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int space[101][10001];

void compress(int a[])
{
	vector<int> v(a, a + N);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (int i = 0; i < N; ++i)
	{
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
}
// 좌표 압축 함수, 
// 해당 변수가 배열에서 몇번째 크기인지 압축

bool isSame(int a[], int b[])
{
	for (int i = 0; i < N; ++i)
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
// 두 우주를 비교해서 압축된 좌표가 동일하면 균등한 우주

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> space[i][j];
		}
		compress(space[i]);
	}

	int cnt = 0;
	for (int i = 0; i < M - 1; ++i)
	{
		for (int j = i + 1; j < M; ++j)
		{
			if (isSame(space[i], space[j]))
			{
				++cnt;
			}
		}
	}
	cout << cnt;

	return 0;
}