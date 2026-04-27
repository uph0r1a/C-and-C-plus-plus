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

    bool found = false;
    double result = 0;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] < 0 && a[i] > -1)
        {
            result = a[i];
            found = true;
            break;
        }

    cout << fixed << setprecision(6);
    if (!found)
        cout << "Khong co gia tri am nao trong (-1, 0).\n";
    else
        cout << "Gia tri am cuoi cung > -1: " << result << "\n";
    return 0;
}
