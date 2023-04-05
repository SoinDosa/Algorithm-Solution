// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : jihwan0123
// Commented by : Soindosa
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M;
int board[9][9];
int safeCnt;
vector<pair<int, int>> safeZone;
vector<pair<int, int>> virusZone;

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int bfs()
{
	queue<pair<int, int>> q;
	bool isVis[9][9] = {};
	int infested = 0;

	for (pair<int, int> virusPos : virusZone)
	{
		q.push(virusPos);
		isVis[virusPos.first][virusPos.second] = true;
	}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		infested++;
		for (int dir = 0; dir < 4; ++dir)
		{
			int curX = cur.first + dx[dir];
			int curY = cur.second + dy[dir];

			if (oob(curX, curY) == true)
			{
				continue;
			}

			if (board[curX][curY] == 1 || isVis[curX][curY] == true)
			{
				continue;
			}

			isVis[curX][curY] = true;
			q.push({ curX, curY });
		}
	}

	return infested;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int result = 0;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				safeCnt++;
				safeZone.push_back({ i, j });
			}
			else if (board[i][j] == 2)
			{
				virusZone.push_back({ i, j });
			}
		}
		// ���������� ��ǥ�� ���̷��� ��ǥ ����
	}

	int safeZoneSizeCache = safeZone.size();
	for (int i = 0; i < safeZoneSizeCache; ++i)
	{
		board[safeZone[i].first][safeZone[i].second] = 1;
		for (int j = i + 1; j < safeZoneSizeCache; ++j)
		{
			board[safeZone[j].first][safeZone[j].second] = 1;
			for (int k = j + 1; k < safeZoneSizeCache; ++k)
			{
				board[safeZone[k].first][safeZone[k].second] = 1;
				result = max(safeCnt - 3 + (int)virusZone.size() - bfs(), result);
				// �ʱ� �������� ���� - 3 + virus ����
				// - bfs�� ���� Ȯ���� ������ ���� ����(virus ������ ������)
				// �� �� �� �߿��� �ִ븦 ã�´�
				board[safeZone[k].first][safeZone[k].second] = 0;
			}
			board[safeZone[j].first][safeZone[j].second] = 0;
		}
		board[safeZone[i].first][safeZone[i].second] = 0;
	}

	cout << result;

	return 0;
}