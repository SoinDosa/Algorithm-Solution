#include <iostream>

using namespace std;

int table[4][4] = {
	{0, 2, 0, 1},
	{2, 1, 3, 0},
	{0, 3, 2, 1},
	{1, 0, 1, 3}
};
// A = 0, G = 1, C = 2, T = 3

int dna_to_int(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'G':
		return 1;
	case 'C':
		return 2;
	case 'T':
		return 3;
	}
}

char int_to_dna(int n)
{
	switch (n)
	{
	case 0:
		return 'A';
	case 1:
		return 'G';
	case 2:
		return 'C';
	case 3:
		return 'T';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	char input[1000001];
	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}

	for (int i = N - 2; i >= 0; --i)
	{
		input[i] = int_to_dna(table[dna_to_int(input[i])][dna_to_int(input[i + 1])]);
	}

	cout << input[0];

	return 0;
}