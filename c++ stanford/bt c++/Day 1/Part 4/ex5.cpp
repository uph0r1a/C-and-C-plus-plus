#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Cac so 2 chu so co tich = 2 x tong:\n";
    int count = 0;
    for (int num = 10; num <= 99; num++)
    {
        int a = num / 10, b = num % 10;
        if (a * b == 2 * (a + b))
        {
            cout << num
                 << " (" << a << " x " << b << " = " << a * b
                 << " = 2 x (" << a << "+" << b << "))\n";
            count++;
        }
    }
    cout << "Tong cong: " << count << " so.\n";
    return 0;
}
