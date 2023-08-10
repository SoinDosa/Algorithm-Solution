#include <iostream>
#include <queue>
using namespace std;

typedef struct Pos
{
	int x;
	int y;
	int z;
};

const int dx[6] = { 1, 0, 0, -1, 0, 0 };
const int dy[6] = { 0, 1, 0, 0, -1, 0 };
const int dz[6] = { 0, 0, 1, 0, 0, -1 };

char building[31][31][31];
int dist[31][31][31];
int L, R, C;
int stX, stY, stZ;
int outX, outY, outZ;

bool oob(const int& x, const int& y, const int& z)
{
	return (x < 0 || x >= L || y < 0 || y >= R || z < 0 || z >= C);
}

int escape_building(int x, int y, int z)
{
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			fill(dist[i][j], dist[i][j] + C, 0);
		}
	}

	queue<Pos> q;
	dist[x][y][z] = 1;
	q.push({ x, y, z });
	while (!q.empty())
	{
		int curX = q.front().x;
		int curY = q.front().y;
		int curZ = q.front().z;
		q.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nxtX = curX + dx[dir];
			int nxtY = curY + dy[dir];
			int nxtZ = curZ + dz[dir];

			if (oob(nxtX, nxtY, nxtZ))
			{
				continue;
			}

			if (nxtX == outX && nxtY == outY && nxtZ == outZ)
			{
				return dist[curX][curY][curZ];
			}

			if (dist[nxtX][nxtY][nxtZ] != 0 || building[nxtX][nxtY][nxtZ] == '#')
			{
				continue;
			}
			dist[nxtX][nxtY][nxtZ] = dist[curX][curY][curZ] + 1;
			q.push({ nxtX, nxtY, nxtZ });
		}
	}

	return -1;
}

int main()
{
	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
		{
			break;
		}

		for (int i = 0; i < L; ++i)
		{
			for (int j = 0; j < R; ++j)
			{
				for (int k = 0; k < C; ++k)
				{
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S')
					{
						stX = i;
						stY = j;
						stZ = k;
					}

					if (building[i][j][k] == 'E')
					{
						outX = i;
						outY = j;
						outZ = k;
					}
				}
			}
		}

		int time = escape_building(stX, stY, stZ);

		if (time == -1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in " << time << " minute(s).\n";
		}
	}
}
