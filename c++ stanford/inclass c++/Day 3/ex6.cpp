#include <iostream>
using namespace std;

int GCD_Euclid(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int GCD_DuyetTruc(int a, int b)
{
    int min = (a < b) ? a : b;
    for (int i = min; i >= 1; i--)
        if (a % i == 0 && b % i == 0)
            return i;
    return 1;
}

int main(int argc, char const *argv[])
{
    int a = 0, b = 0;

    cout << "Nhap so thu 1: ";
    cin >> a;
    cout << "Nhap so thu 2: ";
    cin >> b;

    cout << "\nUoc so chung lon nhat cua " << a << " va " << b << ":\n";
    cout << "Cach Euclid: " << GCD_Euclid(a, b) << "\n";
    cout << "Cach duyet: " << GCD_DuyetTruc(a, b) << "\n";

    return 0;
}
