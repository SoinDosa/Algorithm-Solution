// Authored by : heheHwang
// Co-authored by : -
// Commented by : Soindosa
#include <iostream>
#include <set>

using namespace std;

int main(void) {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    set<int> s;
    // 홍익대학교의 명소 위치
    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i)
    {
        bool isPlace;
        cin >> isPlace;

        if (isPlace)
        {
            s.insert(i);
        }
    }
    // 각 명소의 위치를 저장

    int pos = 1;
    while (Q--)
    {
        int op;
        cin >> op;

        switch (op)
        {
        case 1:
            int idx;
            cin >> idx;
            if (s.find(idx) != s.end())
            {
                s.erase(idx);
            }
            else
            {
                s.insert(idx);
            }
            break;
        case 2:
            int dist;
            cin >> dist;

            pos = (pos + dist - 1) % N + 1;
            // pos가 N을 초과하면 pos를 1부터 다시 시작
            break;
        case 3:
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                set<int>::iterator it = s.lower_bound(pos);
                // pos보다 크거나 같은 위치의 명소를 찾는다
                if (it != s.end())
                {
                    cout << *it - pos << '\n';
                }
                // 있다면 해당 위치 - pos
                else
                {
                    cout << N - pos + *s.begin() << '\n';
                }
                // 없다면 pos에서 N까지 + 가장 앞 위치에 있는 명소
            }
            break;
        }
    }

    return 0;
}