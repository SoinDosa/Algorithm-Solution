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
// ��������
// ã������ ä���� 100001... �� ����� 0�� ���������� ��ȣ��ư Ŭ��Ƚ���� ����� ī��Ʈ���� ����
// to_string�� ���� �ذ�