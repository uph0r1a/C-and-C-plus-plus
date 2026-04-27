#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout << "Nhap mot ky tu: ";
    cin >> c;

    if (c >= 'a' && c <= 'z')
        cout << "Ky tu hoa: " << static_cast<char>(toupper(c)) << "\n";
    else
        cout << "Ky tu vua nhap khong thuoc khoang tu 'a' toi 'z'\n";

    return 0;
}