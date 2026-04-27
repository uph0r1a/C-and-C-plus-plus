#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap n (>= 3): ";
        cin >> n;
    } while (n < 3);
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }

    const double EPS = 1e-9;
    int idx = -1;
    for (int i = 1; i < n - 1; i++)
        if (fabs(a[i] - a[i - 1] * a[i + 1]) < EPS)
        {
            idx = i;
            break;
        }

    cout << fixed << setprecision(4);
    if (idx == -1)
        cout << "Khong co vi tri nao thoa a[i] = a[i-1]*a[i+1].\n";
    else
        cout << "Vi tri thoa: " << idx + 1
             << "  (a[" << idx + 1 << "]=" << a[idx]
             << " = " << a[idx - 1] << " x " << a[idx + 1] << ")\n";
    return 0;
}
