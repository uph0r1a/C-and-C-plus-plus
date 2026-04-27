#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap xau: ";
    getline(cin, s);

    char target;
    cout << "Nhap ky tu can tim: ";
    cin >> target;

    int cnt = 0;
    cout << "Vi tri cua '" << target << "': ";
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == target)
        {
            cout << (i + 1) << " ";
            cnt++;
        }

    cout << "\nTong so lan xuat hien: " << cnt << "\n";
    return 0;
}
