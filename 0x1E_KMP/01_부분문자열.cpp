#include <iostream>
#include <vector>

using namespace std;

vector<int> failure(const string& s)
{
	vector<int> f(s.size());
	int j = 0;

	for (int i = 1; i < s.size(); ++i)
	{
		while (j > 0 && s[i] != s[j])
		{
			j = f[j - 1];
		}
		
		if (s[i] == s[j])
		{
			f[i] = ++j;
		}
	}

	return f;
}
// KMP 실패 함수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string S, P;
	cin >> S >> P;

	vector<int> f = failure(P);
	// 실패함수의 결과 배열을 생성
	int j = 0;

	for (int i = 0; i < S.size(); ++i)
	{
		while (j > 0 && S[i] != P[j])
		{
			j = f[j - 1];
		}

		if (S[i] == P[j])
		{
			j++;
		}

		if (j == P.size())
		{
			cout << 1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}
// 오답정리 : string.find()를 사용하면 시간초과로 실패