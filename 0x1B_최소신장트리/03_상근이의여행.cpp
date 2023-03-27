#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;

	cin >> T;
	while (T--)
	{
		int N = 0;
		int M = 0;

		cin >> N >> M;
		while (M--)
		{
			int a = 0;
			int b = 0;

			cin >> a >> b;
		}
		cout << N - 1 << '\n';
		// 비행 스케줄은 항상 연결그래프를 이룬다는 가정이 있으므로 가능
	}
	
	return 0;
}
// 이게 MST문제라고?? 뭔가 이상한데
// 그리고 비행기 경로가 불가사리 모양으로 뻗어있으면 가운데로 돌아오는 경우도 포함해야되지 않나?