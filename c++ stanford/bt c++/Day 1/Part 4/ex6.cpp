#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const double LIMIT_A = 2.102;
    const double LIMIT_B = 2000.0;

    int n_a = 1;
    double sum_a = 1.0;
    while (1)
    {
        double next = sum_a + 1.0 / (2 * n_a + 1);
        if (next >= LIMIT_A)
            break;
        sum_a = next;
        n_a++;
    }
    cout << fixed << setprecision(6);
    cout << "Phan a: n lon nhat = " << n_a
         << " (S = " << sum_a << " < " << LIMIT_A << ")\n";

    int n_b = 1;
    while (1)
    {
        int next = n_b + 1;
        double val = exp(next) - 1999.0 * log10(next);
        if (val >= LIMIT_B)
            break;
        n_b = next;
    }
    double val_b = exp(n_b) - 1999.0 * log10(n_b);
    cout << "Phan b: n lon nhat = " << n_b
         << " (e^n - 1999*log10(n) = " << val_b << " < " << LIMIT_B << ")\n";

    return 0;
}
