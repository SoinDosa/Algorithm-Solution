#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int S[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int minGap = 0x7F7F7F7F;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> S[i][j];
		}
	}

	vector<int> brute(N);
	fill(brute.begin() + N / 2, brute.end(), 1);

	do
	{
		vector<int> starTeam;
		vector<int> linkTeam;

		for (int i = 0; i < N; ++i)
		{
			if (brute[i] == 1)
			{
				starTeam.push_back(i);
			}
			else
			{
				linkTeam.push_back(i);
			}
		}

		int starTeamAbility = 0;
		int linkTeamAbility = 0;

		for (int i = 0; i < N / 2; ++i)
		{
			for (int j = i + 1; j < N / 2; ++j)
			{
				starTeamAbility += S[starTeam[i]][starTeam[j]] + S[starTeam[j]][starTeam[i]];
				linkTeamAbility += S[linkTeam[i]][linkTeam[j]] + S[linkTeam[j]][linkTeam[i]];
			}
		}

		minGap = min(minGap, abs(starTeamAbility - linkTeamAbility));
	} while (next_permutation(brute.begin(), brute.end()));
	// 팀이 구해질 수 있는 모든 경우의 수를 통해 최소 능력치차이를 구한다

	cout << minGap;

	return 0;
}