#include <iostream>
#include <cstring>
using namespace std;

void BackwardString(char *string)
{
    int j = 0;
    for (int i = strlen(string) - 1; i >= 0; i--)
    {
        cout << string[i];
    }
}

int main(int argc, char const *argv[])
{
    char string[] = "Gravity";

    BackwardString(string);
    return 0;
}
