#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string N = "";
	int numbers[9] = { 0, };

	cin >> N;
	for (char n : N)
	{
		if (n == '9')
		{
			numbers[6]++;
			continue;
		}
		numbers[n - '0']++;
	}
	
	if (numbers[6] % 2 != 1)
	{
		numbers[6] /= 2;
	}
	else
	{
		++numbers[6] /= 2;
	}

	cout << *max_element(begin(numbers), end(numbers));
	// std::max_element, min_element 사용해서 문제풀기

	return 0;
}