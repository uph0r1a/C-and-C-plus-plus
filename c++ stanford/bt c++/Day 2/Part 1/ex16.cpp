#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    const string str = "Cong ty Stanford - Dao tao va phat trien cong nghe";
    const string target = "Stanford";
    char findChar = 't';

    cout << "Chuoi goc: " << str << "\n\n";

    size_t pos = str.find(target);
    if (pos != string::npos)
    {
        size_t end = str.find(' ', pos);
        string word = (end == string::npos) ? str.substr(pos) : str.substr(pos, end - pos);
        cout << "Tu 'Stanford': " << word << " (tai vi tri " << pos + 1 << ")\n";
    }
    else
    {
        cout << "Khong tim thay 'Stanford'\n";
    }

    size_t first = str.find(findChar);
    size_t last = str.rfind(findChar);

    if (first != string::npos)
    {
        cout << "Vi tri dau tien cua '" << findChar << "': " << first + 1 << "\n";
        cout << "Vi tri cuoi cung cua '" << findChar << "': " << last + 1 << "\n";
    }
    else
    {
        cout << "Khong tim thay '" << findChar << "'\n";
    }

    return 0;
}
