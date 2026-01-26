#include <iostream>
#include <cstdlib>
#include <ctime>
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

int main()
{
    srand(static_cast<unsigned>(time(0)));

    Die die1, die2;

    int playerTotal = 0;
    int computerTotal = 0;
    char choice;

    cout << "Welcome to the Game of 21!\n";

    do
    {
        die1.roll();
        die2.roll();
        computerTotal += die1.getValue() + die2.getValue();

        cout << "\nDo you want to roll the dice? (y/n): ";
        cin >> choice;

        if (tolower(choice) != 'y')
            break;

        die1.roll();
        die2.roll();

        int rollSum = die1.getValue() + die2.getValue();
        playerTotal += rollSum;

        cout << "You rolled: " << die1.getValue()
             << " and " << die2.getValue() << endl;
        cout << "Your total is now: " << playerTotal << endl;

    } while (playerTotal <= 21);

    cout << "\n===== GAME OVER =====\n";
    cout << "Your total: " << playerTotal << endl;
    cout << "Computer total: " << computerTotal << endl;

    if (playerTotal > 21)
    {
        cout << "You went over 21. You lose.\n";
    }
    else if (computerTotal > 21)
    {
        cout << "Computer went over 21. You win!\n";
    }
    else if (playerTotal > computerTotal)
    {
        cout << "You win!\n";
    }
    else if (computerTotal > playerTotal)
    {
        cout << "Computer wins.\n";
    }
    else
    {
        cout << "It's a tie!\n";
    }

    return 0;
}
