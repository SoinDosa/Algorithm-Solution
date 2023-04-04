#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N, M, R, C, L;
int board[51][51];
bool pipeShape[7][4] = {
	{true, true, true, true},
	{true, false, true, false},
	{false, true, false, true},
	{false, true, true, false},
	{true, true, false, false},
	{true, false, false, true},
	{false, false, true, true}
};

bool oob(const int& x, const int& y)
{
	return (x < 0 || x >= N || y < 0 || y >= M);
}

int bfs()
{
	queue<pair<int, int>> q;
	vector<int> dirArr;
	int dist[51][51] = {};

	q.push({ R, C });
	dist[R][C] = 1;

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		int curPipe = board[cur.first][cur.second] - 1;

		q.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			if (pipeShape[curPipe][dir] == false)
			{
				continue;
			}
			
			int curX = cur.first + dx[dir];
			int curY = cur.second + dy[dir];

			if (oob(curX, curY) == true)
			{
				continue;
			}

			if (board[curX][curY] == 0 || dist[curX][curY] != 0)
			{
				continue;
			}

			if (pipeShape[board[curX][curY] - 1][(dir + 2) % 4] == false)
			{
				continue;
			}
			// 파이프모양이 연결되어있지 않을 경우

			dist[curX][curY] = dist[cur.first][cur.second] + 1;
			q.push({ curX, curY });
		}
	}

	int zoneCnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (dist[i][j] != 0 && dist[i][j] <= L)
			{
				zoneCnt++;
			}
		}
	}

	return zoneCnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> board[i][j];
			}
		}

		cout << '#' << test_case << ' ' << bfs() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}