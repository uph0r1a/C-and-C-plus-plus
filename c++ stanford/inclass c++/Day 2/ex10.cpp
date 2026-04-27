#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;

    cout << "Nhap vao 1 chuoi: ";
    getline(cin, str);

    int tk[10] = {};

    for (char ch : str)
        if (isdigit((unsigned char)ch))
            tk[ch - '0']++;

    cout << "\nThong ke chu so trong chuoi \"" << str << "\":\n";
    for (int i = 0; i <= 9; i++)
        if (tk[i] > 0)
            cout << "  '" << i << "': " << tk[i] << " lan\n";

    return 0;
}
