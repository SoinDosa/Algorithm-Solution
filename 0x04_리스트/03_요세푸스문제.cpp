#include <iostream>
#include <vector>

using namespace std;

int pre[5000] = { 0, };
int nxt[5000] = { 0, };
// ���Ḯ��Ʈ�� ����� ���� �迭

int main()
{
	int N = 0;
	int K = 0;
	int length = 0;
	// ���� ���Ḯ��Ʈ�� ���̸� ����
	vector<int> josephus;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		pre[i] = (i == 1) ? N : i - 1;
		nxt[i] = (i == N) ? 1 : i + 1;
		length++;
	} 
	// ���� ���Ḯ��Ʈ ����

	int index = 1;
	for (int cur = 1; length != 0; cur = nxt[cur])
	{
		if (index == K)
		{
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			// ���� ����� pre�� �����Ǵ� ����� pre
			// ���� ����� nxt�� �����Ǵ� ����� nxt
			josephus.push_back(cur);
			index = 1;
			--length;
		}
		// K ��°�� �� ����
		else
		{
			++index;
		}
	}

	cout << '<';
	for (int i = 0; i < josephus.size(); ++i)
	{
		cout << josephus[i];
		if (i != josephus.size() - 1)
		{
			cout << ", ";
		}
		// ������ ���ڿ��� ������ ��µ��� �ʾƾ� �Ѵ�
	}
	cout << '>';

	return 0;
}