// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <set>
#include <tuple>
// for tie()

using namespace std;

pair<int, int> probLevel[100'001];
// [문제번호]의 { 난이도, 분류 } 저장
set<int> probByL[101];
// [난이도] 별로 문제 저장
set<int> probByGL[101][101];
// [분류][난이도] 별로 문제 저장

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--)
	{
		int P, L, G;
		cin >> P >> L >> G;
		probLevel[P] = { L, G };
		probByL[L].insert(P);
		probByGL[G][L].insert(P);
	}

	cin >> N;
	while (N--)
	{
		string op;
		cin >> op;

		if (op == "recommend")
		{
			int G, x;
			cin >> G >> x;

			if (x == 1)
			{
				for (int i = 100; i >= 0; --i)
				{
					if (probByGL[G][i].empty())
					{
						continue;
					}
					cout << *(prev(probByGL[G][i].end())) << '\n';
					break;
				}
			}
			else
			{
				for (int i = 0; i <= 100; ++i)
				{
					if (probByGL[G][i].empty())
					{
						continue;
					}
					cout << *probByGL[G][i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "recommend2")
		{
			int x;
			cin >> x;

			if (x == 1)
			{
				for (int i = 100; i >= 0; --i)
				{
					if (probByL[i].empty())
					{
						continue;
					}
					cout << *(prev(probByL[i].end())) << '\n';
					break;
				}
			}
			else
			{
				for (int i = 0; i <= 100; ++i)
				{
					if (probByL[i].empty())
					{
						continue;
					}
					cout << *probByL[i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "recommend3")
		{
			int ans = -1;
			// 조건을 만족하는 값이 없으면 -1을 출력해야함
			int x, L;
			cin >> x >> L;

			if (x == 1)
			{
				for (int i = L; i <= 100; ++i)
				{
					if (probByL[i].empty())
					{
						continue;
					}
					ans = *probByL[i].begin();
					break;
				}
			}
			else
			{
				for (int i = L - 1; i >= 0; --i)
				{
					if (probByL[i].empty())
					{
						continue;
					}
					ans = *(prev(probByL[i].end()));
					break;
				}
			}
			cout << ans << '\n';
		}
		else if (op == "add")
		{
			int P, L, G;
			cin >> P >> L >> G;
			
			probLevel[P] = { L, G };
			probByL[L].insert(P);
			probByGL[G][L].insert(P);
		}
		else if (op == "solved")
		{
			int P;
			cin >> P;

			int L, G;
			tie(L, G) = probLevel[P];
			probByL[L].erase(P);
			probByGL[G][L].erase(P);
		}
	}

	return 0;
}