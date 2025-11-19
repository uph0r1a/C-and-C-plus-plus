#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(0));
    int a = (rand() % 100) + 1, guess;
    while (guess != a)
    {
        cout << "Guess the number: ";
        cin >> guess;
        if (guess > a)
        {
            cout << "Too high,try again\n";
        }
        else if (guess < a)
        {
            cout << "Too low, try agin\n";
        }
        else
        {
            cout << "Correct\n";
            break;
        }
    }

    return 0;
}
