// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/a84f083cdee3436f9f46acdef175e55f

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N = 0;
	stack<int> st;
	long long height = 0;
	long long result = 0;
	// result�� long long �̾���ϴ� ����
	// �־��� ��� N �� �ǹ��� 80000 - N���� ������ ��ġ��ŷ�� �� ����, 79999 + 79998 ... + 2 + 1
	// �뷫 80000 * 40000 = 32000000000(32��)

	cin >> N;
	while (N--)
	{
		cin >> height;
		while (!st.empty() && st.top() <= height)
		{
			st.pop();
		}
		// ���� ��ȣ�� �ǹ��� ���� ��ȣ�� �ǹ������� ���������� �ǹ�
		result += st.size();
		// st.size�� ���� ���������� �� �� �ִ� �������� ������ �ǹ�
		st.push(height);
	}
	// ���� ��ȣ���� �� �� �ִ� �ǹ��� ������ �ƴ� ���� ������ ������ �� �ִ� ������ ������ ������ �� Ǯ�̹�

	cout << result;

	return 0;
}