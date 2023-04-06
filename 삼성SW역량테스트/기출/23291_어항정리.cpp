#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int N, K;
deque<int> board[101];
// { 층수, 높이 }

int result;
int minFish = 0x7FFFFFFF;
int maxFish = 0;

void set_fish(const int& height)
{
	int tmp[101][101] = {};

	for (int i = height - 1; i >= 0; --i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			int gap = 0;

			if (j != board[i].size() - 1)
			{
				gap = (board[i][j] - board[i][j + 1]) / 5;
				tmp[i][j] -= gap;
				tmp[i][j + 1] += gap;
			}

			if (i != 0)
			{
				gap = (board[i][j] - board[i - 1][j]) / 5;
				tmp[i][j] -= gap;
				tmp[i - 1][j] += gap;
			}
		}
	}

	for (int i = height - 1; i >= 0; --i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			board[i][j] += tmp[i][j];
		}
	}
}

void first_roll()
{
	for (int i = 0; i < N; ++i)
	{
		if (board[0][i] == minFish)
		{
			board[0][i]++;
		}
	}

	int rollingWidth = 1;
	int rollingHeight = 1;
	// 굴려야하는 어항의 높이, 너비
	while (board[0].size() - rollingWidth >= rollingHeight)
	{
		for (int y = rollingWidth - 1; y >= 0; --y)
		{
			for (int x = 0; x < rollingHeight; ++x)
			{
				board[rollingWidth - y].push_back(board[x][y]);
			}
		}

		for (int x = 0; x < rollingHeight; ++x)
		{
			for (int y = 0; y < rollingWidth; ++y)
			{
				board[x].pop_front();
			}
		}

		if (rollingWidth == rollingHeight)
		{
			rollingHeight++;
		}
		else
		{
			rollingWidth++;
		}
	}
	// 굴린다
	set_fish(rollingHeight);

	int frontToBack = board[0].size() - rollingWidth;

	for (int y = 0; y < rollingWidth; ++y)
	{
		for (int x = 0; x < rollingHeight; ++x)
		{
			board[0].push_back(board[x][y]);
		}
	}

	for (int x = 0; x < rollingHeight; ++x)
	{
		for (int y = 0; y < rollingWidth; ++y)
		{
			board[x].pop_front();
		}
	}

	for (int i = 0; i < frontToBack; ++i)
	{
		board[0].push_back(board[0].front());
		board[0].pop_front();
	}
	// 원상복구
}

void second_roll()
{
	int rollingWidth = N / 2;
	int rollingHeight = 1;

	for (int cnt = 0; cnt < 2; ++cnt)
	{
		for (int x = rollingHeight - 1; x >= 0; --x)
		{
			for (int y = rollingWidth - 1; y >= 0; --y)
			{
				board[(rollingHeight * 2) - x - 1].push_back(board[x][y]);
			}
		}

		for (int x = 0; x < rollingHeight; ++x)
		{
			for (int y = 0; y < rollingWidth; ++y)
			{
				board[x].pop_front();
			}
		}

		if (cnt != 1)
		{
			rollingWidth /= 2;
		}
		rollingHeight *= 2;
	}
	// 굴린다
	
	set_fish(rollingHeight);

	for (int y = 0; y < rollingWidth; ++y)
	{
		for (int x = 0; x < rollingHeight; ++x)
		{
			board[0].push_back(board[x][y]);
		}
	}

	for (int x = 0; x < rollingHeight; ++x)
	{
		for (int y = 0; y < rollingWidth; ++y)
		{
			board[x].pop_front();
		}
	}
	// 원상복구
}
void clear_Bowl()
{
	first_roll();
	second_roll();
}

bool is_end()
{
	minFish = 0x7FFFFFFF;
	maxFish = 0;
	minFish = *min_element(board[0].begin(), board[0].end());
	maxFish = *max_element(board[0].begin(), board[0].end());

	return maxFish - minFish <= K;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int input;
		cin >> input;
		board[0].push_back(input);
	}
	
	while (is_end() == false)
	{
		clear_Bowl();
		result++;
	}

	cout << result;

	return 0;
}