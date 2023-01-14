#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N = 0;
    int input = 0;
    vector<int> v;
    
    cin >> N;
    while (N--)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << '\n';
    }
    
    return 0;
}
