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
		// isdigit : char 형이 숫자에 해당하는 ASCII 코드값인지 아닌지 판별
		// true라면 0이 아닌 값을 반환하는데 true == 1이므로 평소처럼 isdigit() == true로 하면 안먹힘 
		// 습관을 바꿀필요가 있다
		else
		{
			cout << stringToInt[op] << '\n';
		}
	}

	return 0;
}