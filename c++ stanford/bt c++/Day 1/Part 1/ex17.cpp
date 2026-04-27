#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Truoc khi doi: a = " << a << ", b = " << b << "\n";

    int t = a;
    a = b;
    b = t;
    cout << "Sau khi doi (bien phu): a = " << a << ", b = " << b << "\n";

    t = a;
    a = b;
    b = t;

    a ^= b;
    b ^= a;
    a ^= b;
    cout << "Sau khi doi: a = " << a << ", b = " << b << "\n";

    return 0;
}
