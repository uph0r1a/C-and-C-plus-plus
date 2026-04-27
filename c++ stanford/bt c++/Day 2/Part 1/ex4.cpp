#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void inMang(const vector<double> &a)
{
    for (double x : a)
        cout << x << " ";
    cout << "\n";
}

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
        cout << "  a[" << (i + 1) << "]: ";
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    cout << "Tang dan: ";
    inMang(a);

    sort(a.begin(), a.end(), greater<double>());
    cout << "Giam dan: ";
    inMang(a);

    return 0;
}
