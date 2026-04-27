#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    do
    {
        cout << "Nhap so nguyen co 4 chu so (1000-9999): ";
        cin >> num;
    } while (num < 1000 || num > 9999);

    int d1 = num / 1000;
    int d2 = (num / 100) % 10;
    int d3 = (num / 10) % 10;
    int d4 = num % 10;

    int tong = d1 + d2 + d3 + d4;

    cout << "Tong cac chu so = " << tong << "\n";
    cout << "Chu so dau = " << d1 << "\n";
    cout << "Chu so cuoi = " << d4 << "\n";
    return 0;
}
