#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void Lottery()
{
    int lottery[5], user[5], number_of_match = 0;
    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        lottery[i] = rand() % 10;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter each number of your lottery ticket: ";
        while (1)
        {
            cin >> user[i];
            if (user[i] >= 1 && user[i] <= 9)
            {
                if (user[i] == lottery[i])
                {
                    number_of_match++;
                }

                break;
            }
            cout << "Each lottery number must be between 1 and 9\nRe-enter you number: ";
        }
    }
    cout << "Lottery number: ";
    for (int i = 0; i < 5; i++)
    {
        cout << lottery[i];
    }
    cout << "\nNumber of matching digits: " << number_of_match << endl;
    if (number_of_match == 5)
    {
        cout << "You are a grand prize winner.";
    }
}

int main(int argc, char const *argv[])
{
    Lottery();
    return 0;
}
