#include <iostream>
#include <cstring>
using namespace std;

int WordCount(char *string)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' && ((string[i - 1] >= 'a' && string[i - 1] <= 'z') || (string[i - 1] >= 'A' && string[i - 1] <= 'Z')))
        {
            count++;
        }
        
        
    }
    return count;
}

int main(int argc, char const *argv[])
{
    char string[] = "Four score and seven years ago";
    cout << WordCount(string);
    return 0;
}
