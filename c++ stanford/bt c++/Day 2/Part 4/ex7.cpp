#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cout << "Nhap chuoi: ";
    getline(cin, s);

    int numChars = 0;
    for (char c : s)
        if (c != ' ')
            numChars++;

    int numWords = 0;
    string w;
    istringstream iss(s);
    while (iss >> w)
        numWords++;

    cout << "Do dai chuoi (ca dau cach): " << s.size() << "\n";
    cout << "So ky tu (khong tinh dau cach): " << numChars << "\n";
    cout << "So tu: " << numWords << "\n";
    return 0;
}
