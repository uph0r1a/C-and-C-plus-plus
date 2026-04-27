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
        cout << "Nhap n (>= 1): ";
        cin >> n;
    } while (n < 1);
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cout << "  a[" << i + 1 << "]: ";
        cin >> a[i];
    }
    double x;
    cout << "Nhap x: ";
    cin >> x;

    int idxFar = 0;
    for (int i = 1; i < n; i++)
        if (fabs(a[i] - x) > fabs(a[idxFar] - x))
            idxFar = i;

    cout << fixed << setprecision(4);
    cout << "Gia tri xa " << x << " nhat: " << a[idxFar]
         << " (vi tri " << idxFar + 1 << ", khoang cach " << fabs(a[idxFar] - x) << ")\n";
    return 0;
}