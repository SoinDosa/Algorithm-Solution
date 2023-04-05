#include <iostream>

using namespace std;

int N;
long long A[12];
int opCnt[4];
// { µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À } »ç¿ëÈ½¼ö
long long maxOutput = -1000000001;
// ¿À´äÁ¤¸®, maxOutputÀ» 0ÀÌ ¾Æ´Ñ À½¼ö·Î ÃÊ±âÈ­ÇØ¾ßÇÔ
long long minOutput = 1000000001;

void func(int idx, long long output)
{
	if (idx >= N - 1)
	{
		maxOutput = max(maxOutput, output);
		minOutput = min(minOutput, output);
		return;
	}

	if (opCnt[0] > 0)
	{
		opCnt[0]--;
		func(idx + 1, output + A[idx + 1]);
		opCnt[0]++;
	}

	if (opCnt[1] > 0)
	{
		opCnt[1]--;
		func(idx + 1, output - A[idx + 1]);
		opCnt[1]++;
	}

	if (opCnt[2] > 0)
	{
		opCnt[2]--;
		func(idx + 1, output * A[idx + 1]);
		opCnt[2]++;
	}

	if (opCnt[3] > 0)
	{
		opCnt[3]--;
		func(idx + 1, output / A[idx + 1]);
		opCnt[3]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		cin >> opCnt[i];
	}

	func(0, A[0]);
	cout << maxOutput << '\n' << minOutput;

	return 0;
}