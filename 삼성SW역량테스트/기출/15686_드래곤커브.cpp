// Authored by : yongjunleeme
// Co-authored by : -
// Commented by : Soindosa
#include <iostream>
#include <vector>

using namespace std;

int N;
bool board[101][101];
// [y][x]�ӿ� ����

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	while (N--)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<int> v;
		v.push_back(d % 4);
		board[y][x] = true;

		while (g--)
		{
			int vSizeCache = v.size();

			for (int i = vSizeCache - 1; i >= 0; --i)
			{
				v.push_back((v[i] + 1) % 4);
			}
			// ���� ���� ����� ����� �ݽð�������� 90�� ���� �� �Ųٷ� ���� �ִ´�
		}

		int vSizeCache = v.size();
		for (int i = 0; i < vSizeCache; ++i)
		{
			switch (v[i])
			{
			case 0:
				x++;
				break;
			case 1:
				y--;
				break;
			case 2:
				x--;
				break;
			case 3:
				y++;
				break;
			}
			board[y][x] = true;
		}
		// ���Ϳ� ����� ���赵�� ���� �巡�� Ŀ�� �׸���
	}

	int result = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (board[i][j] == false)
			{
				continue;
			}
			if (board[i + 1][j] == true && board[i][j + 1] == true && board[i + 1][j + 1] == true)
			{
				result++;
			}
			// �巡��Ŀ�� ���������� ������� ���簢���̸� ����
		}
	}
	cout << result;

	return 0;
}