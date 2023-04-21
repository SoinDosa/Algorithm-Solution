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
	// [�й�] = ������û Ŭ�� �ð�

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
	// �й��� �������� ������û Ŭ�� �ð����� ����

	vector<pair<string, int>> v(signup.begin(), signup.end());
	
	sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });
	// ���ٽ��� Ȱ���� ����, ���� ��û�� ����� �켱������ �ȴ�

	int en = min(K, (int)v.size());
	// ���� ��û���� ���� ���� ���� �ο����� ���� �� �����Ƿ� ó��������Ѵ�

	for (int i = 0; i < en; ++i)
	{
		cout << v[i].first << '\n';
	}

	return 0;
}