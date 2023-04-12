#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<string> us;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;

	cin >> n;
	while (n--)
	{
		string peopleName;
		string op;

		cin >> peopleName >> op;
		if (op == "enter")
		{
			us.insert(peopleName);
		}
		else
		{
			us.erase(peopleName);
		}
	}

	vector<string> result(us.begin(), us.end());
	// 벡터를 생성할때 iterator를 넘겨주면 복사할 수 있음
	sort(result.begin(), result.end(), greater<string>());

	for (string s : result)
	{
		cout << s << '\n';
	}

	return 0;
}