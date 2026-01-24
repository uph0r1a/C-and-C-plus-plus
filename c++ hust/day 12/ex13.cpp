#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Coin
{
public:
    Coin(float val)
    {
        value = val;
        toss();
    }

    void toss()
    {
        if (rand() % 2 == 0)
        {
            sideUp = "Head";
        }
        else
        {
            sideUp = "Tail";
        }
    }

    string getSideUp() const
    {
        return sideUp;
    }

    float getValue() const
    {
        return value;
    }

private:
    string sideUp;
    float value;
};

int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    Coin quarter(0.25);
    Coin dime(0.1);
    Coin nickel(0.05);

    float balance = 0;

    while (balance < 1)
    {
        quarter.toss();
        dime.toss();
        nickel.toss();

        if (quarter.getSideUp() == "Head")
        {
            balance += quarter.getValue();
        }

        if (dime.getSideUp() == "Head")
        {
            balance += dime.getValue();
        }

        if (nickel.getSideUp() == "Head")
        {
            balance += nickel.getValue();
        }
    }

    if (balance == 1)
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "You lose" << endl;
    }

    return 0;
}
