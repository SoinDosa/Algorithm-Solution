#include <iostream>

using namespace std;

int N;
int M;
int K;
int noteBook[41][41];
int R;
int C;
int sticker[11][11];

void PasteSticker(int x, int y)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (sticker[i][j] == 1)
			{
				noteBook[x + i][y + j] = 1;
			}
		}
	}
}

bool Pasteable(int x, int y)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (noteBook[x + i][y + j] == 1 && sticker[i][j] == 1)
			{
				return false;
			}
		}
	}
	PasteSticker(x, y);

	return true;
}
// 위치 x,y에 종이를 붙일 수 있으면 붙이고 true 반환

void Rotate()
{
	int tmp[11][11] = {};

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			tmp[i][j] = sticker[i][j];
		}
	}

	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			sticker[i][j] = tmp[R - j - 1][i];
		}
	}
	
	swap(R, C);
}
// 90도 회전

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	while (K--)
	{
		cin >> R >> C;
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				cin >> sticker[i][j];
			}
		}

		for (int rot = 0; rot < 4; ++rot)
		{
			bool isPaste = false;

			for (int x = 0; x <= N - R; ++x)
			{
				if (isPaste == true)
				{
					break;
				}

				for (int y = 0; y <= M - C; ++y)
				{
					if (Pasteable(x, y))
					{
						isPaste = true;
						break;
					}
					// 종이를 붙일 수 있으면 붙였다는 표시를 남기고 반복문 break
				}
			}

			if (isPaste == true)
			{
				break;
			}

			Rotate();
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (noteBook[i][j] == 1)
			{
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	
	return 0;
}