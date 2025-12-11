#include <iostream>
#include <vector>
using namespace std;

bool Winner(vector<int> tickets, int winningNumber)
{
    for (int i = 0; i < tickets.size(); i++)
    {
        if (winningNumber == tickets[i])
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> tickets = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int winningNumber;
    cout << "Enter a winning number: ";
    while (1)
    {
        cin >> winningNumber;
        if (winningNumber >= 10000 && winningNumber <= 99999)
        {
            break;
        }
        cout << "Winng number must be only 5 digits\nRe-enter a winning number: ";
    }

    if (Winner(tickets, winningNumber))
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "You didnt win" << endl;
    }

    return 0;
}
