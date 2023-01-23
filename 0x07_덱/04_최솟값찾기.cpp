// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a3aef39bd578432d814a0be26957bc9c
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    int L = 0;
    deque<pair<int, int>> dq;
    // dq�� �Էµ� ���� index�� value �� �� ������


    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        int input;

        cin >> input;

        while (!dq.empty() && dq.back().second >= input)
        {
            dq.pop_back();
        }
        // ���ο� ���ڰ� deque ������ ���� ū ���� �����̰� back�� ��ġ�ϵ��� ��
        // deque ���� ���ڵ��� �������� ���¸� �����ϰ� �ǰ�, ������ ���� ���� ���� �׻� front�� ��ġ�ϰ� ��

        dq.push_back({ i, input });
        // ���ο� ���ڴ� �׻� ����

        if (dq.front().first <= i - L)
        {
            dq.pop_front();
        }
        // ������ ����� ����

        cout << dq.front().second << ' ';
    }

    return 0;
}
// �켱���� ť�� Ȱ���� Ǯ�̵� �˾ƺ���, �޸𸮴� �� ��Ƹ���