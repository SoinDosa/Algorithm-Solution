#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S;
	vector<string> result;

	cin >> S;
	
	int sLength = S.length();

	for (int i = 0; i < sLength; ++i)
	{
		result.push_back(S.substr(i, sLength));
		//S.erase(S.begin());
	}
	// substr로 나눠서 하나씩 넣는거나
	// S.begin을 하나씩 지워서 삽입하는거나
	// 별차이 없음

	sort(result.begin(), result.end());

	for (string e : result)
	{
		cout << e << '\n';
	}

	return 0;
}