#include <iostream>
#include <vector>
#include <cmath>
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

    double x;
    cout << "Nhap x can tim: ";
    cin >> x;

    const double EPS = 1e-9;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (fabs(a[i] - x) < EPS)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
        cout << "Tim thay " << x << " tai vi tri " << (pos + 1) << " (chi so " << pos << ")\n";
    else
        cout << x << "khong co trong day.\n";

    return 0;
}
