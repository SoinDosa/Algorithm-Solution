#include <iostream>
#include <algorithm>

using namespace std;

int A[51];
int B[51];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
	}
	sort(B, B + N, greater<int>());

	int total = 0;

	for (int i = 0; i < N; ++i)
	{
		total += A[i] * B[i];
	}

	cout << total;

	return 0;
}