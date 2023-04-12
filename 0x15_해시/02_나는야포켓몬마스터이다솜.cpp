#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> stringToInt;
string intToString[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> intToString[i];
		stringToInt[intToString[i]] = i;
	}

	while (M--)
	{
		string op;

		cin >> op;
		if (isdigit(op[0])) 
		{
			cout << intToString[stoi(op)] << '\n';
		} 
		// isdigit : char ���� ���ڿ� �ش��ϴ� ASCII �ڵ尪���� �ƴ��� �Ǻ�
		// true��� 0�� �ƴ� ���� ��ȯ�ϴµ� true == 1�̹Ƿ� ���ó�� isdigit() == true�� �ϸ� �ȸ��� 
		// ������ �ٲ��ʿ䰡 �ִ�
		else
		{
			cout << stringToInt[op] << '\n';
		}
	}

	return 0;
}