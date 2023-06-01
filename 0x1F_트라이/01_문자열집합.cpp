#include <iostream>

using namespace std;

const int ROOT = 1;
// Ʈ������ �ֻ�� ���
int unused = 2;
// Ʈ���̿� ������ ����� ��ȣ
const int MX = 10000 * 500 + 1;
// �ִ� ���尡���� ������ ��
bool chk[MX];
// �ش� ��尡 ���ڿ��� ������ ���θ� ����
int nxt[MX][26];
// �ڽĳ�带 ����, nxt[����� ��ȣ][�ڽĳ���� ����] = �ڽĳ���� ��ȣ
// �ڽ��� ���ٸ� -1
// �ش� ���������� ���ĺ� �ҹ��ڸ��� ����ϹǷ� 26

int c2i(char c)
{
	return c - 'a';
}
// char�� int�� ��ȯ���ִ� �Լ�

void insert(const string& s)
{
	int cur = ROOT;

	for (char c : s)
	{
		if (nxt[cur][c2i(c)] == -1)
		{
			nxt[cur][c2i(c)] = unused++;
			// unused�� �ڽ������� ���ְ� 1 ������Ų��
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