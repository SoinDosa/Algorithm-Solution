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
	// getline(string)은 '\n'을 구분자로 사용하여 문자열을 입력받고 '\n'을 버퍼에서 지움
	// cin은 '\n', '띄어쓰기', 'tab'을 구분자로 사용하며 버퍼를 지우지 않기 때문에,
	// cin이후 getline을 사용한다면 cin.ignore()와 같은 함수를 사용해 버퍼를 지워줘야한다

	for (int i = 1; i <= N; ++i)
	{
		string input;
		getline(cin, input);
		cout << i << ". " << input << '\n';
	}

	return 0;
}