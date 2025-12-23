#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string password;
    bool hasUpperCase = false, hasLowerCase = false, hasDigit = false, hasSixCharacter = false;

    cout << "Enter your password: ";
    getline(cin, password);

    if (password.size() >= 6)
    {
        hasSixCharacter = true;
    }

    for (char c : password)
    {
        if (isupper(c))
        {
            hasUpperCase = true;
        }

        if (islower(c))
        {
            hasLowerCase = true;
        }

        if (isdigit(c))
        {
            hasDigit = true;
        }
    }

    if (hasUpperCase && hasLowerCase && hasDigit && hasSixCharacter)
    {
        cout << "Verified" << endl;
    }
    if (!hasSixCharacter)
    {
        cout << "The password should be at least six characters long" << endl;
    }
    if (!hasUpperCase)
    {
        cout << "The password should contain at least one uppercase" << endl;
    }
    if (!hasLowerCase)
    {
        cout << "The password should contain at least one lowercase" << endl;
    }
    if (!hasDigit)
    {
        cout << "The password should contain at least one digit" << endl;
    }

    return 0;
}
