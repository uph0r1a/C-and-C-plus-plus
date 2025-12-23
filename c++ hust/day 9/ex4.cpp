#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
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

int LetterCount(const char *str)
{
    int letters = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
            letters++;
    }
    return letters;
}

int main(int argc, char const *argv[])
{
    char text[] = "Four score and seven years ago";

    int words = WordCount(text);
    int letters = LetterCount(text);

    cout << "Word count: " << words << endl;
    cout << fixed << setprecision(2);
    cout << "Average number of letters: "
         << static_cast<float>(letters) / words << endl;

    return 0;
}
