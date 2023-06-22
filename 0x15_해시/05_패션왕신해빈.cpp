#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		unordered_map<string, int> um;
		int result = 1;
		int n;
		cin >> n;

		while (n--)
		{
			string wear, part;
			cin >> wear >> part;
			um[part]++;
		}

		for (auto e : um)
		{
			result *= e.second + 1;
			// +1을 하는 이유 : 입는 경우 한 가지씩과 아예 안입는 경우
		}

		cout << result - 1 << '\n';
		// 알몸인 경우를 제외
	}

	return 0;
}