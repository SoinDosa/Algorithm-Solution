#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int N = 0;
		int M = 0;
		int cnt = 0;
		vector<int> a;
		vector<int> b;

		cin >> N >> M;
		while (N--)
		{
			int input = 0;
			
			cin >> input;
			a.push_back(input);
		}
		while (M--)
		{
			int input = 0;

			cin >> input;
			b.push_back(input);
		}

		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end());

		for (auto i : a)
		{
			for (auto j : b)
			{
				if (j < i)
				{
					cnt++;
				}
				else
				{
					break;
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}