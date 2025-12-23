#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <limits>
using namespace std;

void numberofVowelsandConsonants(char str[], int &countVowel, int &countConsonants)
{
    countVowel = 0, countConsonants = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            countVowel++;
        }
        else if (isalpha(ch))
        {
            countConsonants++;
        }
    }
}

void enterAString(char *&str)
{
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    int size = input.length();
    delete[] str;
    str = new char[size + 1];

    strcpy(str, input.c_str());
}

int main(int argc, char const *argv[])
{
    char *str = nullptr;
    bool flag = true;
    cout << "Enter a string: ";
    char choice;
    int countVowel = 0, countConsonants = 0;
    enterAString(str);

    numberofVowelsandConsonants(str, countVowel, countConsonants);

    do
    {
        cout << "A)Count the number of vowels in the string " << endl
             << "B)Count the number of consonants in the string" << endl
             << "C)Count both the vowels and consonants in the string" << endl
             << "D)Enter another string" << endl
             << "E)Exit the program" << endl;

        cin >> choice;

        if (toupper(choice) == 'A')
        {
            cout << "Number of vowels in the string: " << countVowel << endl;
            continue;
        }
        else if (toupper(choice) == 'B')
        {
            cout << "Number of consonants in the string: " << countConsonants << endl;
            continue;
        }
        else if (toupper(choice) == 'C')
        {
            cout << "Number of vowels and consonants in the string: " << countConsonants + countVowel << endl;
            continue;
        }
        else if (toupper(choice) == 'D')
        {
            enterAString(str);
            numberofVowelsandConsonants(str, countVowel, countConsonants);
        }
        else if (toupper(choice) == 'E')
        {
            flag = false;
        }
        else
        {
            cout << "Invalid choice\nRe-enter your choice: ";
        }
    } while (flag);

    delete[] str;

    return 0;
}
