#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;

    cout << "Nhap vao 1 chuoi: ";
    getline(cin, str);

    cout << "Chuoi goc: " << str << "\n";

    cout << "Chuoi dao nguoc: ";
    for (int i = (int)str.length() - 1; i >= 0; i--)
        cout << str[i];
    cout << "\n";

    return 0;
}
