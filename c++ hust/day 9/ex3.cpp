#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int WordCount(const char *str)
{
    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && !inWord)
        {
            count++;
            inWord = true;
        }
        else if (str[i] == ' ')
        {
            inWord = false;
        }
    }
    return count;
}

int WordCount(const string &str)
{
    int count = 0;
    bool inWord = false;

    for (char c : str)
    {
        if (c != ' ' && !inWord)
        {
            count++;
            inWord = true;
        }
        else if (c == ' ')
        {
            inWord = false;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char string[] = "Four score and seven years ago";
    cout << WordCount(string) << endl;
    return 0;
}
