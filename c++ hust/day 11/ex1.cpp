#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream f("files/file.txt");

    if (!f)
    {
        cout << "Cannot open file" << endl;
        return 1;
    }

    string line;
    int count = 10;
    while (getline(f, line) && count != 0)
    {
        cout << line << endl;
        count--;
    }

    if (count != 0)
    {
        cout << "The entire file has been displayed" << endl;
    }

    f.close();
    return 0;
}
