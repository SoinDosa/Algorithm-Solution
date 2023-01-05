#include <iostream>

using namespace std;

int arr[10000001] = { 0, };
bool occur[2000000];

int main()
{
	// arr�� main �Լ� ���ο� ������ ���ÿ뷮�� �ʰ��ߴٴ� ����� ��µȴ�
	// arr�� heap �������� �ű�ų� vector�� ����ϸ� ���� ����
	// ������ O(n^2)�� �ð����⵵�� Ǯ���ϸ� �ð��ʰ��̴�
	int n = 0;
	int x = 0;
	int result = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < n; ++i)
	{
		// x - arr[i]�� ã���� true�� �ٲ۴�. �̷��� �´� �������� ���� �� �ش� ���� occur�� true�� �Ǹ鼭 �ѽ��� �ִٴ� ���� �ȴ�
		// �������⵵ O(2000000), �ð����⵵ O(n)���� Ǯ �� �ִ� ����̴�
		if (x - arr[i] > 0 && occur[x - arr[i]])
		{
			result++;
		}
		occur[arr[i]] = true;
	}

	cout << result;

	return 0;
}