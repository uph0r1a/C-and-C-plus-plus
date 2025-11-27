#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void Computer_choice(string &computer_choice)
{
    srand(time(0));
    int choice = (rand() % 3) + 1;
    if (choice == 1)
    {
        computer_choice = "Rock";
    }
    else if (choice == 2)
    {
        computer_choice = "Paper";
    }
    else
    {
        computer_choice = "Scissors";
    }
}

void User_choice(string &user_choice)
{
    cout << "Enter your choice(Rock, Paper or Scissors): ";
    while (1)
    {
        cin >> user_choice;
        if (user_choice == "Rock" || user_choice == "Paper" || user_choice == "Scissors")
        {
            break;
        }
        cout << "Invalid choice\nRe-enter your choice(Rock, Paper or Scissors): ";
    }
}

void Display_computer_choice(string computer_choice)
{
    cout << "Computer choice: " << computer_choice<<endl;
}

void Winner(string computer_choice, string user_choice)
{
    if (user_choice == "Rock")
    {
        if (computer_choice == "Paper")
        {
            cout << "Computer win\n";
        }
        else if (computer_choice == "Scissors")
        {
            cout << "You win\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
    if (user_choice == "Paper")
    {
        if (computer_choice == "Scissors")
        {
            cout << "Computer win\n";
        }
        else if (computer_choice == "Rock")
        {
            cout << "You win\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
    if (user_choice == "Scissors")
    {
        if (computer_choice == "Rock")
        {
            cout << "Computer win\n";
        }
        else if (computer_choice == "Paper")
        {
            cout << "You win\n";
        }
        else
        {
            cout << "Draw\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    string computer_choice, user_choice;
    Computer_choice(computer_choice);
    User_choice(user_choice);
    Display_computer_choice(computer_choice);
    Winner(computer_choice, user_choice);
    return 0;
}
