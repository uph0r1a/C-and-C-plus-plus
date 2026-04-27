#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    char target;
    cout << "Ky tu can xoa: ";
    cin >> target;

    int cnt = (int)count(s.begin(), s.end(), target);
    s.erase(remove(s.begin(), s.end(), target), s.end());

    cout << "Da xoa " << cnt << " ky tu '" << target << "'\n";
    cout << "Chuoi ket qua: " << s << "\n";
    return 0;
}
