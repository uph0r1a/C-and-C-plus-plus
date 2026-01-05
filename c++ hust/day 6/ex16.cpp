#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void WSC()
{
    vector<string> teams;
    vector<string> winners;
    string search;
    ifstream f1("files/Teams.txt");

    if (!f1)
    {
        cout << "Cannot open file";
        return;
    }
    int i = 0;
    string teamName;
    while (getline(f1, teamName))
    {
        teams.push_back(teamName);
        cout << teams[i] << endl;
        i++;
    }

    cout << "Enter the name of one of the teams: ";
    int flag = 0;
    while (1)
    {
        getline(cin, search);
        for (int i = 0; i < teams.size(); i++)
        {
            if (teams[i] == search)
            {
                flag = 1;
            }
        }

        if (flag)
        {
            break;
        }
        cout << "Team name didnt exist\nRe-enter the name of one of the teams: ";
    }

    ifstream f2("files/WorldSeriesWinners.txt");
    if (!f2)
    {
        cout << "Cannot open file";
        return;
    }
    string winner;

    while (getline(f2, winner))
    {
        winners.push_back(winner);
    }

    int won = 0;
    for (int i = 0; i < winners.size(); i++)
    {
        if (winners[i] == search)
        {
            won++;
        }
    }

    cout << "From 1903 to 2012, " << search << " has won the World Series " << won << " times";
    f1.close();
    f2.close();
}

int main(int argc, char const *argv[])
{
    WSC();
    return 0;
}
