#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    int result = 0;

    cin >> N;
    while (N--)
    {
        string word;
        stack<int> st;
        bool isGood = true;

        cin >> word;
        for (char c : word)
        {
            if (!st.empty() && st.top() == c)
            {
                st.pop();
                isGood = true;
            }
            else
            {
                st.push(c);
                isGood = false;
            }
        }

        if (st.empty() && isGood)
        {
            result++;
        }
    }
    
    cout << result;

    return 0;
}