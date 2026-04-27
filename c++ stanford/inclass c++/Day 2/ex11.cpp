#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;

    cout << "Nhap vao 1 chuoi: ";
    getline(cin, str);

    int soLan = 0;
    cout << "\nCac vi tri ki tu 'a' xuat hien (vi tri bat dau tu 1):\n";

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] == 'a')
        {
            cout << "Vi tri " << i + 1 << "\n";
            soLan++;
        }
    }

    if (soLan == 0)
        cout << "(khong tim thay)\n";

    cout << "Tong so lan 'a' xuat hien: " << soLan << "\n";

    return 0;
}
