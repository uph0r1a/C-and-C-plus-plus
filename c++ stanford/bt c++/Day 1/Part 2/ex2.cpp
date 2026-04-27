#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cout << "Nhap so nguyen: ";
    cin >> num;

    cout << "He 10 (decimal): " << dec << num << "\n";
    cout << "He 8 (octal): " << oct << num << "\n";
    cout << "He 16 (hexadecimal): " << hex << uppercase << num << "\n";

    cout << dec;
    return 0;
}
