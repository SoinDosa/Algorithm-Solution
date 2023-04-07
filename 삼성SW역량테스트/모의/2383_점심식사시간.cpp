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
	// ��� 1,2�� �������� ����ϴ� ������

	int downTime = board[stairs[0].first][stairs[0].second];
	for (int i = 0; i < stair1.size(); ++i)
	{
		peopleQueue.push_back(stair1[i]);
	}

	if (!peopleQueue.empty())
	{
		sort(peopleQueue.begin(), peopleQueue.end());
		// ��ܰ� ����� ������ ����

		stairQueue.push(peopleQueue.front() + 1 + downTime);
		peopleQueue.pop_front();
		// ���� ����� ����� ��ܿ� �ö�Ž
		while (!peopleQueue.empty() || !stairQueue.empty())
		{
			if (peopleQueue.empty())
			{
				time = stairQueue.front();
				stairQueue.pop();
				continue;
			}
			// peopleQueue�� ����ִٸ� time = stairQueue.front()��, stairQueue.pop ����
			
			if (stairQueue.size() < 3)
			{
				stairQueue.push(peopleQueue.front() + 1 + downTime);
				// ����� ����Ա��� ���� + �������� ����(1) + �������� �ð�
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
	// ��� 1 �ð� ���

	time = 0;
	downTime = board[stairs[1].first][stairs[1].second];
	for (int i = 0; i < stair2.size(); ++i)
	{
		peopleQueue.push_back(stair2[i]);
	}
	if (!peopleQueue.empty())
	{
		sort(peopleQueue.begin(), peopleQueue.end());
		// ��ܰ� ����� ������ ����

		stairQueue.push(peopleQueue.front() + 1 + downTime);
		peopleQueue.pop_front();
		// ���� ����� ����� ��ܿ� �ö�Ž
		while (!peopleQueue.empty() || !stairQueue.empty())
		{
			if (peopleQueue.empty())
			{
				time = stairQueue.front();
				stairQueue.pop();
				continue;
			}
			// peopleQueue�� ����ִٸ� time = stairQueue.front()��, stairQueue.pop ����

			if (stairQueue.size() < 3)
			{
				stairQueue.push(peopleQueue.front() + 1 + downTime);
				// ����� ����Ա��� ���� + �������� ����(1) + �������� �ð�
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
	// ��� 2 �ð� ���

	return max(time1, time);
	// �� ū �ð� return
}

void dfs(const int& cur)
{
	if (cur >= peopleCnt)
	{
		minTime = min(minTime, calc_time());
		// �� ��ܿ� ���� ���
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
	// ���� �����ִ� ����� �� ��ܰ��� �Ÿ� ���
}
// ��Ʈ��ŷ�� ���� ������� ����� �����ϴ� ��� ��츦 Ž���Ѵ�

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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}