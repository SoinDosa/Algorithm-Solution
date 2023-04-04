// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// Commented by : Soindosa
// http://boj.kr/693d1ccff5ef479e848979c746b404b1
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int board[501][501];
vector<vector<pair<int, int>>> tetro;

bool isadj(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
	{
		return abs(a.second - b.second) == 1;
	}
	
	if (a.second == b.second)
	{
		return abs(a.first - b.first) == 1;
	}

	return false;
}
// a�� b�� �����¿�� �������� Ȯ��, a == b�� ���� false�� return

bool isConnect(vector<pair<int, int>>& shape)
{
	bool flag = false;
	// 2�� �̻��� ĭ�� �����Ѱ� ����
	// flag�� ������ ������ 2���� ĭ�� ����� �ɷ� �νĵ� �� ����

	for (int i = 0; i < 4; ++i)
	{
		int cnt = 0;
		// shape[i]�� ������ ĭ�� ��

		for (int j = 0; j < 4; ++j)
		{
			if (isadj(shape[i], shape[j]))
			{
				cnt++;
			}
		}

		if (cnt == 0)
		{
			return false;
		}
		// shape[i]�� �ƿ� ������������

		if (cnt >= 2)
		{
			flag = true;
		}
		// shape[i]�� 2�� �̻��� ĭ�� ������
	}
	
	return flag;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}

	vector<int> brute(16);
	fill(brute.begin() + 12, brute.end(), 1);
	// 4*4���� ���Ƿ� 4ĭ�� ������ �ش� 4ĭ�� �پ��ִ��� Ȯ��
	do
	{
		vector<pair<int, int>> shape;
		
		for (int i = 0; i < 16; ++i)
		{
			if (brute[i] == 1)
			{
				shape.push_back({ i / 4, i % 4 });
			}
		}

		if (isConnect(shape))
		{
			tetro.push_back(shape);
		}
		// shape�� 4�� ����� ����̶�� tetro�� ����
	} while (next_permutation(brute.begin(), brute.end()));

	int result = 0;

	for (int i = 0; i <= N - 4; ++i)
	{
		for (int j = 0; j <= M - 4; ++j)
		{
			for (vector<pair<int, int>> shape : tetro)
			{
				int tot = 0;
				for (pair<int, int> coor : shape)
				{
					tot += board[i + coor.first][j + coor.second];
				}
				result = max(result, tot);
			}
			// {i, j} ���� {N - 4, M - 4}���� ���� ��ġ�ϴ� board�� ������ ��� ���غ��� �ִ밪�� ����
		}
	}
	cout << result;

	return 0;
}
// ��� ����� �̸� �����ΰ� ���ϴ� ���, ��Ʈ��ŷ�� ����� ����� ����