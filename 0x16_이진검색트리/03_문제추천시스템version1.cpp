// Authored by : heheHwang
// Commented by : Soindosa
#include <iostream>
#include <set>

using namespace std;

int problemNum[100001];
// �� ������ ���̵� ����
set<int> difficulty[101];
// �� ���̵��� ������ ��ȣ ����

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	while (N--)
	{
		int P, L;

		cin >> P >> L;
		problemNum[P] = L;
		difficulty[L].insert(P);
	}

	int M;
	cin >> M;
	while (M--)
	{
		string op;
		cin >> op;
		
		if (op == "recommend")
		{
			int x;
			cin >> x;

			if (x == 1)
			{
				for (int i = 100; i > 0; --i)
				{
					if (difficulty[i].empty())
					{
						continue;
					}
					cout << *prev(difficulty[i].end()) << '\n';
					break;
				}
			}
			else
			{
				for (int i = 1; i <= 100; ++i)
				{
					if (difficulty[i].empty())
					{
						continue;
					}
					cout << *difficulty[i].begin() << '\n';
					break;
				}
			}
		}
		else if (op == "add")
		{
			int P, L;
			cin >> P >> L;
			problemNum[P] = L;
			difficulty[L].insert(P);
		}
		else if (op == "solved")
		{
			int P;
			cin >> P;
			difficulty[problemNum[P]].erase(P);
		}
	}

	return 0;
}
// �ٽ� : ���̵��� ������ȣ�� �ٸ� �ڷᱸ���� ������ ȿ�������� �������