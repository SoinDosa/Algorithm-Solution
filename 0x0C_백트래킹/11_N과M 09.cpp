// Authored by : connieya
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
// http://boj.kr/8c038985c8d24ae2a79aa5288f5f4ee3
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M;
int input[10];
int arr[10];
bool isUsed[10];

void func(const int& cur)
{
	if (cur == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';

		return;
	}

	int tmp = 0;
	// �ߺ� �������� Ȯ���ϱ� ���� �ʿ��� �ӽ� ����
	// �Է����� �־����� ���� �ڿ��� �̹Ƿ� 0�� ���� �� ����

	for (int i = 0; i < N; ++i)
	{
		if (isUsed[i] == false && tmp != input[i])
		{
			isUsed[i] = true;
			arr[cur] = input[i];
			tmp = arr[cur];
			// ���� for�� �ȿ��� ���� ������ ������ �װ� ���ο� ������ ������ ���� ������ �ߺ� ����
			func(cur + 1);
			isUsed[i] = false;
		}
		// �� tmp�� ���� ������ ������ ��, ���� ���� ���� �����ϸ� func(cur + 1)�� �����Ű�� ����
		// ���� ���� �Է¹޾Ҵٰ� �ص� ���ο� func���� tmp�� 0���� �ʱ�ȭ�ǹǷ� ���� ����
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}
	sort(input, input + N);
	func(0);

	return 0;
}