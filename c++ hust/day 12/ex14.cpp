#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
using namespace std;

class Die
{
public:
    Die()
    {
        roll();
    }

    void roll()
    {
        value = (rand() % 6) + 1;
    }

    int getValue() const
    {
        return value;
    }

private:
    int value;
};

int main(int argc, char const *argv[])
{
    unsigned seed = time(0);
    srand(seed);

    Die die;
    char choice;
    string find[] = {"Old Boot", "Rusty Can", "Small Minnow", "Golden Carp", "Ancient Treasure Chest", "Legendary Sea Crown"};
    int point = 0;

    do
    {
        die.roll();
        string caught = find[die.getValue() - 1];
        cout << "You caught a " << caught << endl
             << "You got " << die.getValue() << " points" << endl;
        point += die.getValue();

        while (1)
        {
            cout << "Do you want to continue?(y/n)";
            cin >> choice;
            if (tolower(choice) == 'y' || tolower(choice) == 'n')
            {
                break;
            }
            cout << "Invalid choice\n";
        }

    } while (tolower(choice) == 'y');

    cout << "Congratulation. You got " << point << " points.";
    if (point >= 20)
    {
        cout << "Amazing job!!!";
    }
    else if (point >= 10)
    {
        cout << "Goodjob";
    }
    else
    {
        cout << "Goodluck next time";
    }

    return 0;
}
