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
    // ȫ�ʹ��б��� ��� ��ġ
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
    // �� ����� ��ġ�� ����

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
            // pos�� N�� �ʰ��ϸ� pos�� 1���� �ٽ� ����
            break;
        case 3:
            if (s.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                set<int>::iterator it = s.lower_bound(pos);
                // pos���� ũ�ų� ���� ��ġ�� ��Ҹ� ã�´�
                if (it != s.end())
                {
                    cout << *it - pos << '\n';
                }
                // �ִٸ� �ش� ��ġ - pos
                else
                {
                    cout << N - pos + *s.begin() << '\n';
                }
                // ���ٸ� pos���� N���� + ���� �� ��ġ�� �ִ� ���
            }
            break;
        }
    }

    return 0;
}