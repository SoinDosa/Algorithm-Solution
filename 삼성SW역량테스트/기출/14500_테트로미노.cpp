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
// a와 b가 상하좌우로 인접한지 확인, a == b인 경우는 false를 return

bool isConnect(vector<pair<int, int>>& shape)
{
	bool flag = false;
	// 2개 이상의 칸과 인접한가 여부
	// flag가 없으면 떨어진 2개의 칸이 연결된 걸로 인식될 수 있음

	for (int i = 0; i < 4; ++i)
	{
		int cnt = 0;
		// shape[i]와 인접한 칸의 수

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
		// shape[i]가 아예 동떨어져있음

		if (cnt >= 2)
		{
			flag = true;
		}
		// shape[i]가 2개 이상의 칸과 인접함
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
	// 4*4에서 임의로 4칸을 선택해 해당 4칸이 붙어있는지 확인
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
		// shape가 4개 연결된 모양이라면 tetro에 삽입
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
			// {i, j} 부터 {N - 4, M - 4}까지 모양과 일치하는 board의 값들을 모두 더해보고 최대값을 정함
		}
	}
	cout << result;

	return 0;
}
// 모든 모양을 미리 만들어두고 구하는 방법, 백트래킹을 사용한 방법도 존재