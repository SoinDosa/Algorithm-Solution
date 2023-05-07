#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string expression;

	cin >> expression;
	// - �ڿ� ������ ���ڴ� ��� -�� �ٲ۴�
	
	int result = 0;
	string num;
	bool isMinus = false;

	for (int i = 0; i <= expression.size(); ++i)
	{
		if (expression[i] == '-' || expression[i] == '+' || i == expression.size())
		{
			if (isMinus)
			{
				result -= stoi(num);
				num = "";
			}
			else
			{
				result += stoi(num);
				num = "";
			}
		}
		else
		{
			num += expression[i];
		}

		if (expression[i] == '-')
		{
			isMinus = true;
		}
		// -�� ������ �� �ڸ� �� ������ �ٲ۴�
	}
	// <= �� ������ ���� ������ ���(���� �ƹ��͵� ���� ��쵵) �����ϱ� ����

	cout << result;

	return 0;
}