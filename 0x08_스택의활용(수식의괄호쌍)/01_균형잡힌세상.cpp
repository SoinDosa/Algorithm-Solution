#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    while (true)
    {
        stack<char> st;
        string input;
        bool isValid = true;

        getline(cin, input);
        // string 한 줄 받기
        if (input == ".")
        {
            break;
        }

        for (char c : input)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    isValid = false;
                    break;
                }
                else if (st.top() == '(')
                {
                    st.pop();
                }
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    isValid = false;
                    break;
                }
                else if (st.top() == '[')
                {
                    st.pop();
                }
            }
        }

        if (isValid && st.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}