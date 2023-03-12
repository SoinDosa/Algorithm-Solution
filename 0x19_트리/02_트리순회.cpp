#include <iostream>
#include <vector>

using namespace std;

int leftChild[27];
int rightChild[27];

void preOrder(int cur)
{
	cout << char(cur + 'A' - 1);
	if (leftChild[cur] != 0)
	{
		preOrder(leftChild[cur]);
	}
	if (rightChild[cur] != 0)
	{
		preOrder(rightChild[cur]);
	}
}

void innerOrder(int cur)
{
	if (leftChild[cur] != 0)
	{
		innerOrder(leftChild[cur]);
	}
	cout << char(cur + 'A' - 1);
	if (rightChild[cur] != 0)
	{
		innerOrder(rightChild[cur]);
	}
}

void postOrder(int cur)
{
	if (leftChild[cur] != 0)
	{
		postOrder(leftChild[cur]);
	}
	if (rightChild[cur] != 0)
	{
		postOrder(rightChild[cur]);
	}
	cout << char(cur + 'A' - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		char c = 0;
		char l = 0;
		char r = 0;

		cin >> c >> l >> r;
		if (l != '.')
		{
			leftChild[c - 'A' + 1] = l - 'A' + 1;
		}
		if (r != '.')
		{
			rightChild[c - 'A' + 1] = r - 'A' + 1;
		}
	}
	// 알파벳순서 = 인덱스순서이므로 c - 'A' + 1을 인덱스로 줘야한다

	preOrder(1);
	cout << '\n';
	innerOrder(1);
	cout << '\n';
	postOrder(1);

	return 0;
}