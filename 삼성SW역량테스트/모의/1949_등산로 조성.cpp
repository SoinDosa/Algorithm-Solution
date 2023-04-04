#include<iostream>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, K;
int board[9][9];
int maxHeight;

bool OOB(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= N);
}

int BFS(int copiedBoard[9][9])
{
	int maxDist = 0;
	int dist[9][9] = { };
	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (copiedBoard[i][j] == maxHeight)
			{
				q.push({ i, j });
				dist[i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int curX = cur.first + dx[dir];
			int curY = cur.second + dy[dir];

			if (OOB(curX, curY) == true)
			{
				continue;
			}

			if (copiedBoard[curX][curY] < copiedBoard[cur.first][cur.second] && dist[curX][curY] <= dist[cur.first][cur.second])
			{
				q.push({ curX, curY });
				dist[curX][curY] = dist[cur.first][cur.second] + 1;
				maxDist = max(dist[curX][curY], maxDist);
			}
			// 1. ���̰� ���� ��ġ���� ����
			// 2. dist�� ���� dist���� �۰ų� ����
			// �� ������ �����ϸ� ť�� �����Ѵ�
		}
	}

	return maxDist;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		maxHeight = 0;
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> board[i][j];
				if (board[i][j] > maxHeight)
				{
					maxHeight = board[i][j];
				}
			}
		}


		int maxDist = BFS(board);
		// �Ϲ� BFS ����
		for (int k = 1; k <= K; ++k)
		{
			for (int x = 0; x < N; ++x)
			{
				for (int y = 0; y < N; ++y)
				{
					board[x][y] -= k;
					maxDist = max(BFS(board), maxDist);
					board[x][y] += k;
				}
			}
		}
		// 5 * 64 * 64

		cout << "#" << test_case << ' ' << maxDist << '\n';

	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}