#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, num;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		arr.push_back(num);
	}

	int S;
	cin >> S;

	int remain = S;
	int frontPos = 0;
	while (remain > 0 && frontPos < N - 1)
	{
		int maxNum = 0;
		int maxIdx = frontPos;
		int cnt = 0;
		for (int i = frontPos; i < N && cnt <= remain; ++i, ++cnt)
		{
			if (arr[i] > maxNum)
			{
				maxIdx = i;
				maxNum = arr[i];
			}
		}
		// �� �տ� ������ �ִ��� ������ ����
		// ���� ���� �̵�Ƚ���� ���� �迭 ���̺��� ª�ٸ� �׸�

		cnt = maxIdx - frontPos;
		// �ִ� ���� ���� �ε��� - ���� �迭 �� �ո�ŭ swap�� �� ����
		for (int i = maxIdx; i > frontPos; --i)
		{
			swap(arr[i - 1], arr[i]);
		}
		remain -= cnt;
		// remain���� �׸�ŭ ��

		++frontPos;
	}

	for (int e : arr)
	{
		cout << e << ' ';
	}
}
// ������ : swap�� �õ��� �� ���ڰ� ���� ū �ε������� ����ؾ���