#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	cin.ignore();
	// getline(string)�� '\n'�� �����ڷ� ����Ͽ� ���ڿ��� �Է¹ް� '\n'�� ���ۿ��� ����
	// cin�� '\n', '����', 'tab'�� �����ڷ� ����ϸ� ���۸� ������ �ʱ� ������,
	// cin���� getline�� ����Ѵٸ� cin.ignore()�� ���� �Լ��� ����� ���۸� ��������Ѵ�

	for (int i = 1; i <= N; ++i)
	{
		string input;
		getline(cin, input);
		cout << i << ". " << input << '\n';
	}

	return 0;
}