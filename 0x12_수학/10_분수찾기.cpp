// Authored by : SciEm
// Commented by : Soindosa
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio();
    cin.tie(nullptr);

    int X;
    cin >> X;

    int i = 1;
    while (X > i)
    {
        X -= i;
        i++;
    }
    // X에서 1... 2... 3.. 을 빼면서 i번째 대각선의 X번째 수를 찾는다

    int a = X;
    int b = i + 1 - X;
    // i번째 대각선에서 분자와 분모의 합은 i + 1이 된다

    if (i % 2 == 1)
    {
        swap(a, b);
    }
    // 홀수번째 대각선에서는 방향이 바뀌므로 뒤집는다

    cout << a << '/' << b;
    return 0;
}