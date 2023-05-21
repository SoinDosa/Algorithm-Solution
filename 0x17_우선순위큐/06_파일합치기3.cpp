#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	
	while (T--)
	{
		priority_queue<long long, vector<long long>, greater<>> fileSizes;
		int K;
		cin >> K;

		while (K--)
		{
			long long fileSize;
			cin >> fileSize;
			fileSizes.push(fileSize);
		}

		long long result = 0;
		while (fileSizes.size() > 1)
		{
			long long a = fileSizes.top();
			fileSizes.pop();
			long long b = fileSizes.top();
			fileSizes.pop();

			fileSizes.push(a + b);
			result += a + b;
		}

		cout << result << '\n';
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
