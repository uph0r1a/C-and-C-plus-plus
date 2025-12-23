#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string string1, string2, string3;
    int pos = 0;
    cout << "Enter string 1: ";
    getline(cin, string1);

    cout << "Enter string 2: ";
    getline(cin, string2);

    cout << "Enter string 3: ";
    getline(cin, string3);

    while ((pos = string1.find(string2, pos)) != string::npos)
    {
        string1.replace(pos, string2.length(), string3);
        pos += string3.length();
    }

    cout << string1 << endl;
    return 0;
}
