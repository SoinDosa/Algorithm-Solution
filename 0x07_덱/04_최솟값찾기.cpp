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
    // dq는 입력된 값의 index와 value 둘 다 저장함


    cin >> N >> L;
    for (int i = 0; i < N; ++i)
    {
        int input;

        cin >> input;

        while (!dq.empty() && dq.back().second >= input)
        {
            dq.pop_back();
        }
        // 새로운 숫자가 deque 내에서 가장 큰 값의 숫자이고 back에 위치하도록 함
        // deque 안의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은 값은 항상 front에 위치하게 됨

        dq.push_back({ i, input });
        // 새로운 숫자는 항상 삽입

        if (dq.front().first <= i - L)
        {
            dq.pop_front();
        }
        // 범위가 벗어나면 제거

        cout << dq.front().second << ' ';
    }

    return 0;
}
// 우선순위 큐를 활용한 풀이도 알아보자, 메모리는 더 잡아먹음