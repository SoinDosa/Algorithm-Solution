#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> linked[201];
int prevLink[201];
bool isVis[201];

bool check_link(int x)
{
	for (int i = 0; i < linked[x].size(); ++i)
	{
		if (isVis[linked[x][i]])
		{
			continue;
		}

		isVis[linked[x][i]] = true;
		// 이미 탐색된 노드임을 표시

		if (prevLink[linked[x][i]] == 0 || check_link(prevLink[linked[x][i]]))
		{
			prevLink[linked[x][i]] = x;
			return true;
		}
		// linked[x][i] 번 축사에 연결된 소가 없다거나 ||
		// 이미 축사와 연결된 소가 다른 축사와 연결될 수 있다면 true 반환
	}

	return false;
}
// x소에서 연결할 수 있는 축사가 있는지 체크

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int n;
		cin >> n;

		for (int j = 0; j < n; ++j)
		{
			int cn;
			cin >> cn;
			linked[i].push_back(cn);
		}
	}
	// 이분 그래프를 입력받는다
	// 왼쪽에서 갈 수 있는 노드들 입력받음

	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (check_link(i))
		{
			fill(isVis + 1, isVis + 1 + M, false);
			// 소를 바꿀 때마다 방문 배열을 초기화
			++cnt;
		}
		// 1부터 N번 소에서 연결할 수 있는 간선이 있는지 체크
		// 존재한다면 카운트 1 올림
	}
	cout << cnt;
}
// 이분그래프 최대 매칭 문제
// 하 면접... 면접... 면접... 악!
