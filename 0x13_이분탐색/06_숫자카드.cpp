#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N;
	while (N--)
	{
		int input;
		
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());

	cin >> M;
	while (M--)
	{
		int input;

		cin >> input;
		if (binary_search(nums.begin(), nums.end(), input))
		{
			cout << "1 ";
		}
		else
		{
			cout << "0 ";
		}
	}

	return 0;
}