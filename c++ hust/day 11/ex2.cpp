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
    int count = 0;
    while (getline(f, line))
    {
        cout << line << endl;
        count++;

        if (count % 24 == 0)
        {
            printf("Press Enter to continue");
            cin.get();
            system("clear");
        }
    }

    f.close();
    return 0;
}
