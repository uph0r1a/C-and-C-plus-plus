#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    do
    {
        cout << "Nhap so tu nhien n (0 <= n <= 20): ";
        cin >> n;
    } while (n < 0 || n > 20);

    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;

    cout << n << "! = " << fact << "\n";
    return 0;
}
