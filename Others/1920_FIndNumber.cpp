#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	unordered_set<int> A;
	int input = 0;

	cin >> N;
	while (N--)
	{
		cin >> input;
		A.insert(input);
	}

	cin >> N;
	while (N--)
	{
		cin >> input;
		if (A.find(input) != A.end())
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}

	return 0;
}
