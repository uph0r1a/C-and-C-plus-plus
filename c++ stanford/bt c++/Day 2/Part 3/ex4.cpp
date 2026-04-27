#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    double x = 0;
    for (double v : a)
        x = max(x, fabs(v));

    cout << fixed << setprecision(4);
    cout << "x = " << x << "  =>  [" << -x << ", " << x << "] chua tat ca phan tu\n";
    return 0;
}
