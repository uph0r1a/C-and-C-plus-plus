#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int interger, a, b;
    string word1, word2;
    cout << "Enter a 2 digit interger: ";
    while (1)
    {
        cin >> interger;
        if (interger < 100 && interger >= 10)
        {
            break;
        }
        cout << "The interger must be 2 digit\n";
        cout << "Re-enter a 2 digit interger: ";
    }
    a = interger / 10;
    b = interger - (a * 10);

    if (a == 1)
    {
        word1 = "Muoi";
    }
    else if (a == 2)
    {
        word1 = "Hai";
    }
    else if (a == 3)
    {
        word1 = "Ba";
    }
    else if (a == 4)
    {
        word1 = "Bon";
    }
    else if (a == 5)
    {
        word1 = "Nam";
    }
    else if (a == 6)
    {
        word1 = "Sau";
    }
    else if (a == 7)
    {
        word1 = "Bay";
    }
    else if (a == 8)
    {
        word1 = "Tam";
    }
    else if (a == 9)
    {
        word1 = "Chin";
    }
    if (b == 1)
    {
        word2 = "mot";
    }
    else if (b == 2)
    {
        word2 = "hai";
    }
    else if (b == 3)
    {
        word2 = "ba";
    }
    else if (b == 4)
    {
        word2 = "bon";
    }
    else if (b == 5)
    {
        word2 = "nam";
    }
    else if (b == 6)
    {
        word2 = "sau";
    }
    else if (b == 7)
    {
        word2 = "bay";
    }
    else if (b == 8)
    {
        word2 = "tam";
    }
    else if (b == 9)
    {
        word2 = "chin";
    }
    else if (b = 0)
    {
        word2 = "muoi";
    }

    cout << interger << " in Vietnamese is: " << word1 << " " << word2;

    return 0;
}
