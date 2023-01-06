#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<int> s;
	int N = 0;
	int input = 0;
	int v = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		s.insert(input);
	}
	cin >> v;
	cout << s.count(v);

	return 0;
}