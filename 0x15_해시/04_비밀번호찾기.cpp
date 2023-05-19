#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    unordered_map<string, string> um;
    int N, M;
    cin >> N >> M;

    while (N--)
    {
        string domain, password;
        cin >> domain >> password;
        um[domain] = password;
    }

    while (M--)
    {
        string domain;
        cin >> domain;
        cout << um[domain] << '\n';
    }

    return 0;
}