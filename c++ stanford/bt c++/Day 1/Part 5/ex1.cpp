#include <iostream>
#include <string>
using namespace std;

static string rep(int n, char c) { return string(n, c); }

void a_tangDan(int n)
{
    cout << "a) Tang dan (goc trai-duoi):\n";
    for (int i = 1; i <= n; i++)
        cout << rep(i, '#') << "\n";
}

void b_giamDan(int n)
{
    cout << "b) Giam dan (goc trai-tren):\n";
    for (int i = n; i >= 1; i--)
        cout << rep(i, '#') << "\n";
}

void c_giamDanPhai(int n)
{
    cout << "c) Giam dan can phai (goc phai-tren):\n";
    for (int i = n; i >= 1; i--)
        cout << rep(n - i, ' ') << rep(i, '#') << "\n";
}

void d_tangDanPhai(int n)
{
    cout << "d) Tang dan can phai (goc phai-duoi):\n";
    for (int i = 1; i <= n; i++)
        cout << rep(n - i, ' ') << rep(i, '#') << "\n";
}

int main(int argc, char const *argv[])
{
    int n = 8;
    a_tangDan(n);
    cout << "\n";
    b_giamDan(n);
    cout << "\n";
    c_giamDanPhai(n);
    cout << "\n";
    d_tangDanPhai(n);
    cout << "\n";
    return 0;
}