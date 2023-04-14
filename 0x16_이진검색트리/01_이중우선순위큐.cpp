#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;

	cin >> T;
	while (T--)
	{
		multiset<int> ms;
		int k;

		cin >> k;
		while (k--)
		{
			char op;
			int num;

			cin >> op >> num;
			if (op == 'I')
			{
				ms.insert(num);
			}
			else
			{
				if (ms.empty())
				{
					continue;
				}

				if (num == 1)
				{
					ms.erase(prev(ms.end()));
					// �ִ��� ms.end()�� �� ĭ ���� prev(ms.end())���� ���
				}
				else
				{
					ms.erase(ms.begin());
				}
			}
		}

		if (ms.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}

	return 0;
}