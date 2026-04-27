#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double X;
    int n;
    const double RATE = 0.005;

    do
    {
        cout << "So tien goc X (> 0): ";
        cin >> X;
    } while (X <= 0);
    do
    {
        cout << "So thang n (>= 1): ";
        cin >> n;
    } while (n < 1);

    cout << fixed << setprecision(2) << "\n";
    cout << setw(6) << "Thang" << setw(20) << "Tien cuoi thang\n";
    cout << string(26, '-') << "\n";

    double balance = X;
    for (int i = 1; i <= n; i++)
    {
        balance *= (1 + RATE);
        cout << setw(6) << i << setw(20) << balance << "\n";
    }

    cout << "\nSo tien sau " << n << " thang: " << balance << " dong\n";
    cout << "Lai thu duoc: " << balance - X << " dong\n";
    return 0;
}
