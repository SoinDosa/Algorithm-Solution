#include <iostream>

using namespace std;

int N = 0;

void ChatBot(int n)
{
	for (int i = 0; i < N - n; ++i)
	{
		cout << "____";
	}

	cout << "\"����Լ��� ������?\"\n";
	if (n == 0)
	{
		for (int i = 0; i < N - n; ++i)
		{
			cout << "____";
		}
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n"; 
		for (int i = 0; i < N - n; ++i)
		{
			cout << "____";
		}
		cout << "��� �亯�Ͽ���.\n";

		return;
	}
	
	for (int i = 0; i < N - n; ++i)
	{
		cout << "____";
	}
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < N - n; ++i)
	{
		cout << "____";
	}
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < N - n; ++i)
	{
		cout << "____";
	}
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
	
	ChatBot(n - 1);

	for (int i = 0; i < N - n; ++i)
	{
		cout << "____";
	}
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	ChatBot(N);
}