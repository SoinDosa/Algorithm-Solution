// Authored by : diyamea
// Co-authored by : BaaaaaaaaaaarkingDog
// Commented by : Soindosa
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int K, L;
	unordered_map<string, int> signup;
	// [학번] = 수강신청 클릭 시간

	cin >> K >> L;
	for (int i = 0; i < L; ++i)
	{
		string studentID;

		cin >> studentID;
		if (signup.find(studentID) != signup.end())
		{
			signup.erase(studentID);
		}
		signup[studentID] = i;
	}
	// 학번과 최종적인 수강신청 클릭 시간들을 저장

	vector<pair<string, int>> v(signup.begin(), signup.end());
	
	sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });
	// 람다식을 활용한 정렬, 빨리 신청한 사람이 우선순위가 된다

	int en = min(K, (int)v.size());
	// 수강 신청자의 수가 수강 가능 인원보다 적을 수 있으므로 처리해줘야한다

	for (int i = 0; i < en; ++i)
	{
		cout << v[i].first << '\n';
	}

	return 0;
}