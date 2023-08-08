// Authored by : heheHwang
// Commented by : Soindosa
#include <iostream>
#include <vector>
using namespace std;


vector<pair<int, int>> board[2][20];
// board[i][j] : 색깔 i에 대해 \ 방향 대각선에 포함되는 칸들
// (r,c)에 대해 r + c가 짝수면 0색깔, 홀수면 1색깔에 대응하고 분리하여 계산
bool isUsed[2][20];
int result[2];
int N;

void bishop(int idx, int cnt, int color)
{
	if (idx == 2 * N)
	{
		result[color] = max(result[color], cnt);
		return;
	}
	// 해당 색깔에 존재할 수 없는 대각선은 자연스럽게 스킵되며 idx = 2 * N까지 도달한다
	for (pair<int, int> v : board[color][idx])
	{
		int x = v.first;
		int y = v.second;

		if (isUsed[color][x + y])
		{
			continue;
		}
		// 해당 색깔의 \ 대각선이 사용되고 있다면 스킵
		isUsed[color][x + y] = true;
		bishop(idx + 1, cnt + 1, color);
		// / 대각선을 한칸 내리고 비숍 갯수 증가, 색깔 유지
		isUsed[color][x + y] = false;
	}
	bishop(idx + 1, cnt, color);
	// 비숍을 아예 안 두는 경우 / 대각선을 한칸 내린다
	// 같은 색깔이 아니더라도 일단 내리고 본다
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int d;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> d;
			if (d == 1)
			{
				board[(i + j + 1) % 2][i - j - 1 + N].push_back({ i, j });
				//해당 색깔과 해당 \ 대각선에 비숍을 배치할 수 있는 좌표들을 넣는다
			}
		}
	}
	bishop(0, 0, 0);
	bishop(0, 0, 1);
	cout << result[0] + result[1];
}
