#include <iostream>
#include <cstring>
using namespace std;

int StringLength(char *string)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char string[] = "abcd";
    cout << "String length: " << StringLength(string) << endl;
    return 0;
}
