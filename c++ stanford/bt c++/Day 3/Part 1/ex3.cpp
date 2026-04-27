#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void inNguocCString(const char *s, int len)
{
    const char *p = s + len - 1;
    while (p >= s)
    {
        cout << *p;
        p--;
    }
    cout << endl;
}

void inNguocString(const string &str)
{
    for (int i = (int)str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}

string daoNguocChuoi(string str)
{
    reverse(str.begin(), str.end());
    return str;
}

int main(int argc, char const *argv[])
{
    string chuoi;
    cout << "Nhap mot chuoi: ";
    getline(cin, chuoi);

    cout << "Chuoi goc: " << chuoi << endl;
    cout << "Chuoi dao nguoc: ";
    inNguocString(chuoi);

    cout << "Chuoi dao nguoc (dung ham reverse): " << daoNguocChuoi(chuoi) << endl;

    cout << endl;
    const int SIZE = 256;
    char s[SIZE];
    cout << "Nhap chuoi C-string: ";
    cin.ignore();
    cin.getline(s, SIZE);

    int len = (int)strlen(s);
    cout << "Chuoi goc: " << s << endl;
    cout << "Chuoi dao nguoc qua con tro: ";
    inNguocCString(s, len);

    return 0;
}
