#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	int lan = (A % C == 0) ? (A / C) : (A / C + 1);
	int mat = (B % D == 0) ? (B / D) : (B / D + 1);

	cout << L - max(lan, mat);

	return 0;
}