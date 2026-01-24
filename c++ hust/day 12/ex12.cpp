#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Coin
{
public:
    Coin()
    {
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

private:
    string sideUp;
};

int main(int argc, char const *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    Coin coin;
    int head = 0, tail = 0;

    cout << "Initial side: " << coin.getSideUp() << endl;

    for (int i = 0; i < 20; i++)
    {
        coin.toss();
        cout << coin.getSideUp() << endl;

        if (coin.getSideUp() == "Head")
        {
            head++;
            continue;
        }
        tail++;
    }

    cout << "Head: " << head << endl
         << "Tail: " << tail << endl;

    return 0;
}
