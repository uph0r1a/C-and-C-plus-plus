#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool laNguyenAm(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int demNguyenAm(const string &s)
{
    int dem = 0;
    for (char c : s)
        if (laNguyenAm(c))
            dem++;
    return dem;
}

void lietKeNguyenAm(const string &s)
{
    cout << "Cac nguyen am tim duoc:\n";
    bool co = false;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (laNguyenAm(s[i]))
        {
            cout << "  Vi tri " << i << ": '" << s[i] << "'\n";
            co = true;
        }
    }
    if (!co)
        cout << "  (Khong co nguyen am nao)\n";
}

int main(int argc, char const *argv[])
{
    string chuoi;
    cout << "Nhap mot chuoi: ";
    getline(cin, chuoi);

    cout << "Chuoi vua nhap: \"" << chuoi << "\"\n";
    cout << "Do dai chuoi: " << chuoi.size() << " ky tu\n";
    cout << endl;

    lietKeNguyenAm(chuoi);

    cout << "\nTong so nguyen am: " << demNguyenAm(chuoi) << endl;

    return 0;
}
