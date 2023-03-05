#include <iostream>
#include <set>

using namespace std;

int N;
int M;
int arr[8];
set<int> s;

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

	int i = 0;
	for (auto it = s.begin(); it != s.end(); ++it, ++i)
	{
		arr[cur] = *it;
		func(cur + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int num;
		
		cin >> num;
		s.insert(num);
	}
	func(0);

	return 0;
}