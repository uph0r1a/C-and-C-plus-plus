#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Nhap a: ";
    cin >> a;

    do
    {
        cout << "Nhap b (khac 0): ";
        cin >> b;
    } while (b == 0);

    if (a % b == 0)
        cout << a << " chia het cho " << b << "\n";
    else
        cout << a << " khong chia het cho " << b
             << " (du " << a % b << ")\n";
    return 0;
}
