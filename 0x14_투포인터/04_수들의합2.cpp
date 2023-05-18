#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }

    int en = 0;
    int total = 0;
    int cnt = 0;
    for (int st = 0; st < N; ++st)
    {
        while (en < N && total < M)
        {
            total += A[en];
            en++;
        }

        if (total == M)
        {
            cnt++;
        }

        total -= A[st];
    }

    cout << cnt;

    return 0;
}