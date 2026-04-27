#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    cout << "Nhap mot ky tu: ";
    cin >> c;

    if (isalpha(static_cast<unsigned char>(c)))
        cout << "'" << c << "' la chu cai.\n";
    else
        cout << "'" << c << "' khong phai chu cai.\n";

    return 0;
}
