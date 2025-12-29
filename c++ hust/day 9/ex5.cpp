#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

void Capitalizer(char *str)
{
    bool capitalizeNext = true;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (capitalizeNext && isalpha(str[i]))
        {
            str[i] = toupper(str[i]);
            capitalizeNext = false;
        }

        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            capitalizeNext = true;
        }
    }
}

void Capitalizer(string &str)
{
    bool capitalizeNext = true;

    for (char &c : str)
    {
        if (capitalizeNext && isalpha(c))
        {
            c = toupper(c);
            capitalizeNext = false;
        }

        if (c == '.' || c == '!' || c == '?')
        {
            capitalizeNext = true;
        }
    }
}

int main(int argc, char const *argv[])
{
    string temp;

    cout << "Input a string: ";
    getline(cin, temp);

    char *c_string = new char[temp.size() + 1];
    strcpy(c_string, temp.c_str());

    Capitalizer(c_string);

    cout << c_string << endl;

    delete[] c_string;
    return 0;
}
