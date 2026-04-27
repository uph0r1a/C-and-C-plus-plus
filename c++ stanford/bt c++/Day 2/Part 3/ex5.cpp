#include <iostream>
#include <vector>
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

    int idx = -1;
    for (int i = 0; i < n; i++)
        if (a[i] > 2003)
        {
            idx = i;
            break;
        }

    cout << fixed << setprecision(4);
    if (idx == -1)
        cout << "Khong co phan tu nao > 2003.\n";
    else
        cout << "Phan tu dau tien > 2003: " << a[idx]
             << " (vi tri " << idx + 1 << ")\n";
    return 0;
}
