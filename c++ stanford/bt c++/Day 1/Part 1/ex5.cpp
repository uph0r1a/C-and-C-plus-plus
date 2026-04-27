#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double so1, so2;
    cout << "Nhap so thu nhat: ";
    cin >> so1;
    cout << "Nhap so thu hai: ";
    cin >> so2;

    cout << fixed << setprecision(2)
         << setw(10) << so1
         << setw(5) << ""
         << setw(10) << so2
         << "\n";
    return 0;
}
