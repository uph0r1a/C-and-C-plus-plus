#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    do
    {
        cout << "Nhap N (>= 1): ";
        cin >> N;
    } while (N < 1);

    double S1 = (N + 1) / 2.0;
    double S2 = sqrt((double)N * (N + 1) * (2 * N + 1) / 6.0);

    cout << fixed << setprecision(6);
    cout << "S1 = " << S1 << "\n";
    cout << "S2 = " << S2 << "\n";

    return 0;
}
