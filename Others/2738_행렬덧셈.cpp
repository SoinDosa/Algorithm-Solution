#include <iostream>

using namespace std;

int arr[101][101];

int main()
{
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            int input;
            cin >> input;
            arr[i][j] += input;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}