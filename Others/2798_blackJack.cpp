#include <iostream>

using namespace std;

int arr[101];

int main()
{
        int N = 0;
        int M = 0;
        int result = 0;

        cin >> N >> M;
        for (int i = 0; i < N; ++i)
        {
                cin >> arr[i];
        }

        for (int i = 0; i < N - 2; ++i)
        {
                for (int j = i + 1; j < N - 1; ++j)
                {
                        for (int k = j + 1; k < N; ++k)
                        {
                                int sum = arr[i] + arr[j] + arr[k];
                                if (sum <= M && sum > result)
                                {
                                        result = sum;
                                }
                        }
                }
        }

        cout << result;

        return 0;
}
