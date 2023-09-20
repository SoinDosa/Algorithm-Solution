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
		// 맨 앞에 원소의 최댓값이 오도록 유도
		// 만약 남은 이동횟수가 남은 배열 길이보다 짧다면 그만

		cnt = maxIdx - frontPos;
		// 최대 값을 가진 인덱스 - 남은 배열 맨 앞만큼 swap할 수 있음
		for (int i = maxIdx; i > frontPos; --i)
		{
			swap(arr[i - 1], arr[i]);
		}
		remain -= cnt;
		// remain에서 그만큼 뺌

		++frontPos;
	}

	for (int e : arr)
	{
		cout << e << ' ';
	}
}
// 오답노드 : swap을 시도할 때 숫자가 가장 큰 인덱스부터 출발해야함