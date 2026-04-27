#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout << "Nhap ky tu mau (R/G/B): ";
    cin >> c;

    switch (toupper(static_cast<unsigned char>(c)))
    {
    case 'R':
        cout << "RED\n";
        break;
    case 'G':
        cout << "GREEN\n";
        break;
    case 'B':
        cout << "BLUE\n";
        break;
    default:
        cout << "BLACK\n";
        break;
    }

    return 0;
}
