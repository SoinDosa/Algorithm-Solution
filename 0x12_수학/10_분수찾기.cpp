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
    // X���� 1... 2... 3.. �� ���鼭 i��° �밢���� X��° ���� ã�´�

    int a = X;
    int b = i + 1 - X;
    // i��° �밢������ ���ڿ� �и��� ���� i + 1�� �ȴ�

    if (i % 2 == 1)
    {
        swap(a, b);
    }
    // Ȧ����° �밢�������� ������ �ٲ�Ƿ� �����´�

    cout << a << '/' << b;
    return 0;
}