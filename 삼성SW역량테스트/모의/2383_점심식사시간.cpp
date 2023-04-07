#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int peopleCnt;
int board[11][11];

vector<pair<int, int>> peoples;
vector<pair<int, int>> stairs;
deque<int> stair1;
deque<int> stair2;
int minTime = 0x7FFFFFFF;

int calc_time()
{
	int time = 0;
	deque<int> peopleQueue;
	queue<int> stairQueue;
	// 계단 1,2가 공통으로 사용하는 변수들

	int downTime = board[stairs[0].first][stairs[0].second];
	for (int i = 0; i < stair1.size(); ++i)
	{
		peopleQueue.push_back(stair1[i]);
	}

	if (!peopleQueue.empty())
	{
		sort(peopleQueue.begin(), peopleQueue.end());
		// 계단과 가까운 순서로 정렬

		stairQueue.push(peopleQueue.front() + 1 + downTime);
		peopleQueue.pop_front();
		// 가장 가까운 사람이 계단에 올라탐
		while (!peopleQueue.empty() || !stairQueue.empty())
		{
			if (peopleQueue.empty())
			{
				time = stairQueue.front();
				stairQueue.pop();
				continue;
			}
			// peopleQueue가 비어있다면 time = stairQueue.front()로, stairQueue.pop 수행
			
			if (stairQueue.size() < 3)
			{
				stairQueue.push(peopleQueue.front() + 1 + downTime);
				// 사람이 계단입구에 도착 + 내려가기 시작(1) + 내려가는 시간
				peopleQueue.pop_front();
			}
			else
			{
				stairQueue.push((stairQueue.front() > peopleQueue.front() + 1) ? (stairQueue.front() + downTime) : (peopleQueue.front() + 1 + downTime));
				stairQueue.pop();
				peopleQueue.pop_front();
			}
		}
	}
	int time1 = time;
	// 계단 1 시간 계산

	time = 0;
	downTime = board[stairs[1].first][stairs[1].second];
	for (int i = 0; i < stair2.size(); ++i)
	{
		peopleQueue.push_back(stair2[i]);
	}
	if (!peopleQueue.empty())
	{
		sort(peopleQueue.begin(), peopleQueue.end());
		// 계단과 가까운 순서로 정렬

		stairQueue.push(peopleQueue.front() + 1 + downTime);
		peopleQueue.pop_front();
		// 가장 가까운 사람이 계단에 올라탐
		while (!peopleQueue.empty() || !stairQueue.empty())
		{
			if (peopleQueue.empty())
			{
				time = stairQueue.front();
				stairQueue.pop();
				continue;
			}
			// peopleQueue가 비어있다면 time = stairQueue.front()로, stairQueue.pop 수행

			if (stairQueue.size() < 3)
			{
				stairQueue.push(peopleQueue.front() + 1 + downTime);
				// 사람이 계단입구에 도착 + 내려가기 시작(1) + 내려가는 시간
				peopleQueue.pop_front();
			}
			else
			{
				stairQueue.push((stairQueue.front() > peopleQueue.front() + 1) ? (stairQueue.front() + downTime) : (peopleQueue.front() + 1 + downTime));
				stairQueue.pop();
				peopleQueue.pop_front();
			}
		}
	}
	// 계단 2 시간 계산

	return max(time1, time);
	// 더 큰 시간 return
}

void dfs(const int& cur)
{
	if (cur >= peopleCnt)
	{
		minTime = min(minTime, calc_time());
		// 각 계단에 대해 계산
		return;
	}

	int dist = 0;

	dist = abs(peoples[cur].first - stairs[0].first) + abs(peoples[cur].second - stairs[0].second);
	stair1.push_back(dist);
	dfs(cur + 1);
	stair1.pop_back();

	dist = abs(peoples[cur].first - stairs[1].first) + abs(peoples[cur].second - stairs[1].second);
	stair2.push_back(dist);
	dfs(cur + 1);
	stair2.pop_back();
	// 현재 보고있는 사람과 각 계단과의 거리 계산
}
// 백트래킹을 통해 사람들이 계단을 선택하는 모든 경우를 탐색한다

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		peoples.clear();
		stairs.clear();
		peopleCnt = 0;
		minTime = 0x7FFFFFFF;

		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> board[i][j];
				if (board[i][j] == 0)
				{
					continue;
				}

				if (board[i][j] == 1)
				{
					peopleCnt++;
					peoples.push_back({ i, j });
				}
				else
				{
					stairs.push_back({ i, j });
				}
			}
		}
		dfs(0);
		cout << '#' << test_case << ' ' << minTime << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}