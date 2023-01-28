#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 0;
    
    cin >> T;
    while (T--)
    {
        string input;
        stack<char> st;

        cin >> input;
        for (char c : input)
        {
            if (c == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        if (!st.empty())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}