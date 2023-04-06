// Authored by : SciEm
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
bool ladder[31][11];
vector<pair<int, int>> coord;
// �� �� �ִ� ���μ��� �����ϴ� ����

bool isMatch()
{
	for (int c = 1; c <= N; ++c)
	{
		int cur = c;
		// ���� Ÿ���ִ� ���μ�
		for (int r = 1; r <= H; ++r)
		{
			if (ladder[r][cur - 1])
			{
				cur--;
			}
			else if (ladder[r][cur])
			{
				cur++;
			}
			// ��ٸ��� ������ �׸�ŭ cur�� �̵�
		}
		if (cur != c)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> H;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			if (ladder[i][j - 1] == true || ladder[i][j] == true || ladder[i][j + 1] == true)
			{
				continue;
			}
			// ������ ���μ��� ���� �� ����
			coord.push_back({ i, j });
		}
	}

	if (isMatch() == true)
	{
		cout << 0;
		return 0;
	}

	int result = 0x7FFFFFFF;
	int coordSizeCache = coord.size();
	for (int i = 0; i < coordSizeCache; ++i)
	{
		ladder[coord[i].first][coord[i].second] = true;
		if (isMatch() == true)
		{
			result = min(result, 1);
		}
		for (int j = i + 1; j < coordSizeCache; ++j)
		{
			ladder[coord[j].first][coord[j].second] = true;
			if (isMatch() == true)
			{
				result = min(result, 2);
			}
			for (int k = j + 1; k < coordSizeCache; ++k)
			{
				ladder[coord[k].first][coord[k].second] = true;
				if (isMatch() == true)
				{
					result = min(result, 3);
				}
				ladder[coord[k].first][coord[k].second] = false;
			}
			ladder[coord[j].first][coord[j].second] = false;
		}
		ladder[coord[i].first][coord[i].second] = false;
	}

	if (result == 0x7FFFFFFF)
	{
		result = -1;
	}
	cout << result;

	return 0;
}