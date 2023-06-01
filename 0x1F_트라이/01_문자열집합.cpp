#include <iostream>

using namespace std;

const int ROOT = 1;
// 트라이의 최상단 노드
int unused = 2;
// 트라이에 삽입할 노드의 번호
const int MX = 10000 * 500 + 1;
// 최대 저장가능한 글자의 수
bool chk[MX];
// 해당 노드가 문자열의 끝인지 여부를 저장
int nxt[MX][26];
// 자식노드를 저장, nxt[노드의 번호][자식노드의 문자] = 자식노드의 번호
// 자식이 없다면 -1
// 해당 문제에서는 알파벳 소문자만을 사용하므로 26

int c2i(char c)
{
	return c - 'a';
}
// char를 int로 변환해주는 함수

void insert(const string& s)
{
	int cur = ROOT;

	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			nxt[cur][c2i(c)] = unused++;
			// unused를 자식정점에 써주고 1 증가시킨다
		}
		cur = nxt[cur][c2i(c)];
	}
	chk[cur] = true;
}

bool find(const string& s)
{
	int cur = ROOT;

	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			return false;
		}
		cur = nxt[cur][c2i(c)];
	}

	return chk[cur];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < MX; ++i)
	{
		fill(nxt[i], nxt[i] + 26, -1);
	}

	while (N--)
	{
		string s;
		cin >> s;
		insert(s);
	}

	int result = 0;
	while (M--)
	{
		string s;
		cin >> s;
		if (find(s))
		{
			result++;
		}
	}

	cout << result;

	return 0;
}