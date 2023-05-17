#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int AN, BN;
    cin >> AN >> BN;

    vector<int> A(AN, 0);
    vector<int> B(BN, 0);

    for (int i = 0; i < AN; ++i)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    for (int i = 0; i < BN; ++i)
    {
        cin >> B[i];
    }
    sort(B.begin(), B.end());

    vector<int> result;
    for (int e : A)
    {
        if (!binary_search(B.begin(), B.end(), e))
        {
            result.push_back(e);
        }
    }

    cout << result.size() << '\n';

    if (result.size() != 0)
    {
        for (int e : result)
        {
            cout << e << ' ';
        }
    }

    return 0;
}