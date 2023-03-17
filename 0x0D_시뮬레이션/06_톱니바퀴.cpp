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
	// 가장 오른쪽 톱니바퀴가 아니거나, 현재 위치에서 오른쪽 톱니바퀴가 이미 회전하지 않았거나, 오른쪽 톱니와 극이 다를때 오른쪽 톱니바퀴 회전

	if (curGear != 3 && isRotate[curGear + 1] == false && gear[curGear][RIGHT_SIDE] != gear[curGear + 1][LEFT_SIDE])
	{
		rotation(curGear + 1, -clockWise);
	}
	// 이하 동문, 왼쪽 톱니바퀴버전

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
	// 시계방향 회전
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
	// 반시계방향 회전
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
	// 명령어를 입력받고 rotation을 실행
	// 모든 rotation이 실행되면 회전 여부를 체크하는 배열을 초기화

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
	// 점수 체크, 기어가 하나 오를 때마다 점수는 2배씩 증가

	cout << result;

	return 0;
}