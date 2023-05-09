#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string expression;

	cin >> expression;
	// - 뒤에 나오는 숫자는 모두 -로 바꾼다
	
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
		// -가 나오면 그 뒤를 다 음수로 바꾼다
	}
	// <= 인 이유는 식이 끝나는 경우(끝에 아무것도 없는 경우도) 봐야하기 때문

	cout << result;

	return 0;
}