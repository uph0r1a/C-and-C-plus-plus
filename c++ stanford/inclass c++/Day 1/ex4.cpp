#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float soThuc1 = 0, soThuc2 = 0;

    cout << "Nhap so thuc 1: ";
    cin >> soThuc1;
    cout << "Nhap so thuc 2: ";
    cin >> soThuc2;

    cout << fixed << setprecision(2);
    cout << "\nSo thu 1: " << setw(10) << soThuc1 << endl
         << "So thuc 2: " << setw(10) << soThuc2 << endl;

    return 0;
}
