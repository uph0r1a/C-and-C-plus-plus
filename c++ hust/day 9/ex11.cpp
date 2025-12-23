#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void upper(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        word[i] = toupper(word[i]);
    }
}

void lower(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        word[i] = tolower(word[i]);
    }
}

void reverse(char *word)
{
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = word[i];
        word[i] = word[len - 1 - i];
        word[len - 1 - i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int size = 0;
    for (char c : input)
    {
        size++;
    }

    char *str;
    str = new char[size + 1];

    strcpy(str, input.c_str());

    upper(str);
    cout << "Upper: " << str << endl;

    lower(str);
    cout << "Lower: " << str << endl;

    reverse(str);
    cout << "Reverse: " << str << endl;

    delete[] str;
    return 0;
}
