#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long A = 0, B = 0, V = 0;

	cin >> A >> B >> V;

	long long height = V - A;
	long long oneDay = A - B;
	long long result = height / oneDay;

	if (height % oneDay != 0)
	{
		result++;
	}
	// ������ ����Ʈ�� �����ϰ� ���̸� �ö󰡾��ϴ� ���� ����

	cout << result + 1;
	// ������������ ����
}