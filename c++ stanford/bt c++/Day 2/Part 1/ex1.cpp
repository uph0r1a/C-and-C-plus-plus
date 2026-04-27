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
        cout << "a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    double tong = 0, tongAm = 0, tongDuong = 0, tongChan = 0, tongLe = 0;
    for (int i = 0; i < n; i++)
    {
        tong += a[i];
        if (a[i] < 0)
            tongAm += a[i];
        else if (a[i] > 0)
            tongDuong += a[i];

        if ((i + 1) % 2 == 0)
            tongChan += a[i];
        else
            tongLe += a[i];
    }

    cout << fixed << setprecision(4) << "\n";
    cout << "Tong = " << tong << "\n";
    cout << "Trung binh = " << tong / n << "\n";
    cout << "Tong am = " << tongAm << "\n";
    cout << "Tong duong = " << tongDuong << "\n";
    cout << "Tong vi tri chan (2,4,...) = " << tongChan << "\n";
    cout << "Tong vi tri le  (1,3,...) = " << tongLe << "\n";
    return 0;
}