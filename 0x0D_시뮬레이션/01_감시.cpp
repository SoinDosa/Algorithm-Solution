#include <iostream>
#include <vector>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;
int M;
int board[10][10];
int copiedBoard[10][10];
vector<pair<int, int>> cctv;
int blank;

void ApplyVision(int x, int y, int dir)
{
	dir %= 4;
	while (true)
	{
		x += dx[dir];
		y += dy[dir];

		if (x < 0 || x >= N || y < 0 || y >= M)
		{
			return;
		}
		
		if (copiedBoard[x][y] == 6)
		{
			return;
		}

		if (copiedBoard[x][y] != 0)
		{
			continue;
		}

		copiedBoard[x][y] = 7;
	}
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
			if (board[i][j] != 0 && board[i][j] != 6)
			{
				cctv.push_back({ i, j });
			}
			// cctv�� ��ġ�� ���ͷ� ����

			if (board[i][j] == 0)
			{
				blank++;
			}
			// board�� �� ���� ���� ����
		}
	}

	int totalDirCase = 1 << 2 * cctv.size();
	// 4������ �÷��׸� ����Ͽ� ��� CCTV�� ���� ����Ǽ��� �˻��� ��
	// ������ ����� ���� 4^cctv.size(), ����Ʈ�����ڷ� ǥ���ϸ� �̿� ���� 2^(2 * cctv.size()) -> 4^cctv.size()

	for (int dirCase = 0; dirCase < totalDirCase; ++dirCase)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				copiedBoard[i][j] = board[i][j];
			}
		}

		int dirFlag = dirCase;
		int totalBlank = 0;

		for (int i = 0; i < cctv.size(); ++i)
		{
			int dir = dirFlag % 4;
			// �÷��׸� 4�� ���� ������ ��, ���� ���� �ڸ���
			dirFlag /= 4;
			// �׸��� 4�� ������

			int cctvX = cctv[i].first;
			int cctvY = cctv[i].second;

			if (board[cctvX][cctvY] == 1)
			{
				ApplyVision(cctvX, cctvY, dir);
			}
			else if (board[cctvX][cctvY] == 2)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 2);
			}
			else if (board[cctvX][cctvY] == 3)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
			}
			else if (board[cctvX][cctvY] == 4)
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
				ApplyVision(cctvX, cctvY, dir + 2);
			}
			else
			{
				ApplyVision(cctvX, cctvY, dir);
				ApplyVision(cctvX, cctvY, dir + 1);
				ApplyVision(cctvX, cctvY, dir + 2);
				ApplyVision(cctvX, cctvY, dir + 3);
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (copiedBoard[i][j] == 0)
				{
					totalBlank++;
				}
			}
		}

		blank = min(blank, totalBlank);
	}

	cout << blank;

	return 0;
}