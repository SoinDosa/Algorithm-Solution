#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	int K = 0;
	list<int> human;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		human.push_back(i);
	}

	auto it = human.begin();

	cout << '<';
	while (!human.empty())
	{
		for (int i = 0; i < K - 1; ++i)
		{
			it++;
			if (it == human.end())
			{
				it = human.begin();
			}
		}

		cout << *it;
		if (human.size() > 1)
		{
			cout << ", ";
		}
		else
		{
			cout << '>';
		}

		it = human.erase(it);
		if (it == human.end())
		{
			it = human.begin();
		}
		// iterator를 통해 컨테이너의 요소를 삭제시킬 때는 반환값을 반복자에 다시 넣어준다
	}

	return 0;
}