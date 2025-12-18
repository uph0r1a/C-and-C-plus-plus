#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct
{
    string name;
    int number, pointScore;
} SoccerPlayer;

void inputData(string &name)
{
    while (1)
    {
        getline(cin, name);
        if (!name.empty())
        {
            break;
        }
        cout << "Player name cannot be empty\nRe-enter the player names: ";
    }
}

void inputData(int &number)
{
    while (1)
    {
        cin >> number;
        if (number >= 0)
        {
            break;
        }
        cout << "Number cannot be negative\nRe-enter the number: ";
    }
}

void SoccerScore(SoccerPlayer player[12])
{
    int totalPoint = 0, MVPNumber, MVPPointScored = 0;
    string MVPPlayer;
    for (int i = 0; i < 12; i++)
    {
        cout << "Player " << i + 1 << endl;
        cout << "Enter player " << i + 1 << " name: ";
        inputData(player[i].name);

        cout << "Enter player " << i + 1 << " number: ";
        inputData(player[i].number);

        cout << "Enter player " << i + 1 << " point scored: ";
        inputData(player[i].pointScore);
        totalPoint += player[i].pointScore;

        if (player[i].pointScore >= MVPPointScored)
        {
            MVPPointScored = player[i].pointScore;
            MVPNumber = player[i].number;
            MVPPlayer = player[i].name;
        }
        cin.ignore();
    }

    system("clear");

    cout << "---------------------------------------------------" << endl;
    cout << "|MVP Number: " << MVPNumber << "\tMVP Name: " << MVPPlayer << setw(24) << "|" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << left
         << setw(15) << "|Player name"
         << setw(15) << "|Player number"
         << setw(20) << "|Player point scored"
         << "|\n";

    for (int i = 0; i < 12; i++)
    {
        cout << left
             << setw(15) << ("|" + player[i].name)
             << setw(15) << ("|" + to_string(player[i].number))
             << setw(20) << ("|" + to_string(player[i].pointScore))
             << "|\n";
    }
    cout << "---------------------------------------------------" << endl;
    cout << "|" << "Total point: " << totalPoint << right << setw(36) << "|" << endl;
    cout << "---------------------------------------------------" << endl;
}

int main(int argc, char const *argv[])
{
    SoccerPlayer player[12];
    SoccerScore(player);
    return 0;
}
