#include <iostream>
#include <vector>

using namespace std;

int pre[5000] = { 0, };
int nxt[5000] = { 0, };
// 연결리스트를 만들기 위한 배열

int main()
{
	int N = 0;
	int K = 0;
	int length = 0;
	// 원형 연결리스트의 길이를 저장
	vector<int> josephus;

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		pre[i] = (i == 1) ? N : i - 1;
		nxt[i] = (i == N) ? 1 : i + 1;
		length++;
	} 
	// 원형 연결리스트 구현

	int index = 1;
	for (int cur = 1; length != 0; cur = nxt[cur])
	{
		if (index == K)
		{
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			// 다음 노드의 pre는 삭제되는 노드의 pre
			// 이전 노드의 nxt는 삭제되는 노드의 nxt
			josephus.push_back(cur);
			index = 1;
			--length;
		}
		// K 번째일 때 제거
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
		// 마지막 숫자에는 반점이 출력되지 않아야 한다
	}
	cout << '>';

	return 0;
}