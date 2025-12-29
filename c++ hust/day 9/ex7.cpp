#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
    string temp, str;
    char *first = nullptr;
    char *middle = nullptr;
    char *last = nullptr;
    int count = 0;

    cout << "Enter your full name: ";
    getline(cin, temp);

    for (size_t i = 0; i < temp.size(); i++)
    {
        char c = temp[i];

        if (c == ' ')
        {
            count++;
            if (count == 1)
            {
                first = new char[str.size() + 1];
                strcpy(first, str.c_str());
                str = "";
            }
            else if (count == 2)
            {
                middle = new char[str.size() + 1];
                strcpy(middle, str.c_str());
                str = "";
            }
        }
        else
        {
            str += c;
        }
    }

    last = new char[str.size() + 1];
    strcpy(last, str.c_str());

    char *fullName = new char[temp.size() + 3];
    strcpy(fullName, last);
    strcat(fullName, ", ");
    strcat(fullName, first);
    strcat(fullName, " ");
    strcat(fullName, middle);

    cout << fullName << endl;

    delete[] first;
    delete[] middle;
    delete[] last;
    delete[] fullName;

    return 0;
}
