// Authored by : cpprhtn
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/b8488e82105d49e89ca6f39fd8ee665b
#include <iostream>

using namespace std;

int N;
int paper[2200][2200];
int cnt[3];

bool isSamePaper(int x, int y, int n)
{
	for (int i = x; i < x + n; ++i)
	{
		for (int j = y; j < y + n; ++j)
		{
			if (paper[x][y] != paper[i][j])
			{
				return false;
				// n * n ������ ������ �ϳ��� �ٸ��ٸ� false 
			}
		}
	}
	return true;
}
// �ش� ���� ���ΰ� ���� ���ڷθ� ä���� �ִ��� Ȯ��
// n�� ������ ���� ����

void func(int x, int y, int z)
{
	if (isSamePaper(x, y, z))
	{
		cnt[paper[x][y] + 1]++;
		return;
	}

	int n = z / 3;
	// ���� ���̸� 1/3���� ����

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			func(x + i * n, y + j * n, n);
			// �� 9���� �����Ͽ� func �����
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> paper[i][j];
		}
	}
	
	func(0, 0, N);

	for (int i = 0; i < 3; ++i)
	{
		cout << cnt[i] << '\n';
	}

	return 0;
}