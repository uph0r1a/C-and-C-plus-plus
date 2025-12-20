#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

typedef struct
{
    string name;
    float cost;
    int numberOfDrink;
} DrinkMachine;

void MachineSimulator(DrinkMachine drinkMachine[5])
{
    int choice;
    bool flag = true;
    float totalMoney = 0;
    do
    {
        cout << "------------------------------------------------------" << endl;
        cout << left << "|" << setw(20) << "Drink Name" << "|" << setw(10) << "Cost" << "|" << setw(20) << "Number in Machine" << "|" << endl;
        cout << "------------------------------------------------------" << endl;

        for (int i = 0; i < 5; i++)
        {
            cout << left << "|" << setw(20) << drinkMachine[i].name << "|" << setw(10) << drinkMachine[i].cost << "|" << setw(20) << drinkMachine[i].numberOfDrink << "|" << endl;
        }
        cout << "------------------------------------------------------" << endl;

        cout << "1)Pick a drink" << endl
             << "2)Quit" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int drinkChoice;
            float insertedMoney;
            cout << endl
                 << "Pick a drink" << endl
                 << "1)Cola" << endl
                 << "2)Root Beer" << endl
                 << "3)Lemon-Lime" << endl
                 << "4)Grape Soda" << endl
                 << "5)Cream Soda" << endl
                 << "Enter your choice: ";
            while (1)
            {
                cin >> drinkChoice;
                if (drinkChoice >= 1 && drinkChoice <= 5)
                {
                    break;
                }
                cout << "Invalid choice\nRe-enter choice: ";
            }
            if (drinkMachine[drinkChoice - 1].numberOfDrink == 0)
            {
                cout << "Drink had been sold out";
                break;
            }
            else
            {
                cout << drinkMachine[drinkChoice - 1].name << "'s price is " << drinkMachine[drinkChoice - 1].cost << endl;
                cout << "Insert your money: ";
                while (1)
                {
                    cin >> insertedMoney;
                    if (insertedMoney >= drinkMachine[drinkChoice - 1].cost && insertedMoney >= 0 && insertedMoney <= 1)
                    {
                        cout << "Purchase succesfull" << endl
                             << "Change returned: " << insertedMoney - drinkMachine[drinkChoice - 1].cost << endl;
                        totalMoney += drinkMachine[drinkChoice - 1].cost;
                        drinkMachine[drinkChoice - 1].numberOfDrink--;
                        break;
                    }
                    if (insertedMoney < 0 || insertedMoney > 1.00)
                        cout << "The amount must be between $0.00 and $1.00" << endl
                             << "Re-insert the money: ";
                    else if (insertedMoney < drinkMachine[drinkChoice - 1].cost)
                        cout << "Insufficient money" << endl
                             << "Re-insert the money: ";
                }
            }

            break;
        case 2:
            flag = false;
            cout << "Total money the machine earned: " << totalMoney << endl;
            break;
        default:
            cout << "Invalid choice" << endl
                 << "Re-enter your choice: ";
            break;
        }
    } while (flag);
}

int main(int argc, char const *argv[])
{
    DrinkMachine drinkMachine[5] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda ", 0.80, 20},
    };

    MachineSimulator(drinkMachine);
    return 0;
}