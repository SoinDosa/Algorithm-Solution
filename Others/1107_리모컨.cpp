#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	vector<int> disableNum;

	cin >> N >> M;
	while (M--)
	{
		int input;
		cin >> input;
		disableNum.push_back(input);
	}

	int minGap = abs(N - 100);

	for (int brute = 0; brute <= 999999; ++brute)
	{
		bool isAble = true;
		string bruteString = to_string(brute);

		for (int c : bruteString)
		{
			if (isAble)
			{
				for (int i : disableNum)
				{
					if (c - '0' == i)
					{
						isAble = false;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}

		if (!isAble)
		{
			continue;
		}

		int numClickCnt = bruteString.size();

		minGap = min(minGap, numClickCnt + abs(N - brute));
	}

	cout << minGap;

	return 0;
}
// 오답정리
// 찾으려는 채널이 100001... 등 가운데에 0이 끼어있으면 번호버튼 클릭횟수가 제대로 카운트되지 않음
// to_string을 통해 해결