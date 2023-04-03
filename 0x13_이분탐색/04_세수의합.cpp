#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int U[1001];
vector<int> two;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> U[i];
	}
	sort(U, U + N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			two.push_back(U[i] + U[j]);
		}
	}
	// 2개의 수를 합한 경우를 two 벡터에 삽입
	sort(two.begin(), two.end());
	// 이분탐색을 위해 two 벡터도 정렬한다

	/*for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j < twoSize; ++j)
		{
			if (binary_search(U, U + N, U[i] - two[j]))
			{
				cout << U[i];

				return 0;
			}
		}
	}*/
	// 오답
	// twoSize = N^2이므로 시간초과 발생
	// 아래처럼 binary_sarch를 통해 2logN으로 바꿔줘야한다

	for (int i = N - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (binary_search(two.begin(), two.end(), U[i] - U[j]))
			{
				cout << U[i];
				return 0;
			}
		}
	}
	// 위의 풀이는 N^3, 이 풀이는 N^2logN
}