#include <iostream>
#include <vector>
using namespace std;

bool Winner(const vector<int> &tickets, int winningNumber)
{
    int low = 0;
    int high = tickets.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (tickets[mid] == winningNumber)
            return true;
        else if (tickets[mid] < winningNumber)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> tickets = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int winningNumber;

    cout << "Enter a winning number: ";
    while (true)
    {
        cin >> winningNumber;
        if (winningNumber >= 10000 && winningNumber <= 99999)
            break;

        cout << "Winning number must be only 5 digits\nRe-enter a winning number: ";
    }

    if (Winner(tickets, winningNumber))
        cout << "You win\n";
    else
        cout << "You didn't win\n";

    return 0;
}
