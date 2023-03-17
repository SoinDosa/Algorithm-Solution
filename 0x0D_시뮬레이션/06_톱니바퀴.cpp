#include <iostream>
#include <vector>

using namespace std;

const int TOOTH = 8;
const int RIGHT_SIDE = 2;
const int LEFT_SIDE = 6;

vector<char> gear[4];
bool isRotate[4];

void rotation(int curGear, int clockWise)
{
	isRotate[curGear] = true;

	if (curGear != 0 && isRotate[curGear - 1] == false && gear[curGear][LEFT_SIDE] != gear[curGear - 1][RIGHT_SIDE])
	{
		rotation(curGear - 1, -clockWise);
	}
	// ���� ������ ��Ϲ����� �ƴϰų�, ���� ��ġ���� ������ ��Ϲ����� �̹� ȸ������ �ʾҰų�, ������ ��Ͽ� ���� �ٸ��� ������ ��Ϲ��� ȸ��

	if (curGear != 3 && isRotate[curGear + 1] == false && gear[curGear][RIGHT_SIDE] != gear[curGear + 1][LEFT_SIDE])
	{
		rotation(curGear + 1, -clockWise);
	}
	// ���� ����, ���� ��Ϲ�������

	if (clockWise == 1)
	{
		char temp = gear[curGear][TOOTH - 1];

		for (int i = TOOTH - 1; i >= 0; --i)
		{
			if (i == 0)
			{
				gear[curGear][i] = temp;
				break;
			}
			gear[curGear][i] = gear[curGear][i - 1];
		}
	}
	// �ð���� ȸ��
	else
	{
		char temp = gear[curGear][0];

		for (int i = 0; i < TOOTH; ++i)
		{
			if (i == TOOTH - 1)
			{
				gear[curGear][i] = temp;
				break;
			}
			gear[curGear][i] = gear[curGear][i + 1];
		}
	}
	// �ݽð���� ȸ��
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < TOOTH; ++j)
		{
			char input = 0;

			cin >> input;
			gear[i].push_back(input);
		}
	}

	cin >> t;
	while (t--)
	{
		int curGear = 0;
		int clockWise = 0;

		cin >> curGear >> clockWise;
		rotation(curGear - 1, clockWise);
		fill(isRotate, isRotate + 4, false);
	}
	// ��ɾ �Է¹ް� rotation�� ����
	// ��� rotation�� ����Ǹ� ȸ�� ���θ� üũ�ϴ� �迭�� �ʱ�ȭ

	int score = 1;
	int result = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (gear[i][0] == '1')
		{
			result += score;
		}
		score <<= 1;
	}
	// ���� üũ, �� �ϳ� ���� ������ ������ 2�辿 ����

	cout << result;

	return 0;
}