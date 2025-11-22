#include <iostream>
using namespace std;

void input(int &number_of_spools_ordered, int &number_of_spools_instock, int &special_charge)
{
    int choice, flag = 1;

    cout << "Enter the number of spools ordered: ";
    while (1)
    {
        cin >> number_of_spools_ordered;
        if (number_of_spools_ordered >= 1)
        {
            break;
        }
        cout << "Number of spools ordered cannot be less than 1\nRe-enter the number of spools ordered: ";
    }

    cout << "Enter the number of spools instock: ";
    while (1)
    {
        cin >> number_of_spools_instock;
        if (number_of_spools_instock >= 0)
        {
            break;
        }
        cout << "Number of spools instock cannot be less than 0\nRe-enter the number of spools instock: ";
    }

    cout << "Is there a special shipping charge\n1) Yes\n0)No\nEnter choice: ";
    while (flag)
    {
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the special charge per spool: ";
            while (1)
            {
                cin >> special_charge;
                if (special_charge >= 0)
                {
                    break;
                }
                cout << "Special charge cannot be less than 0\nRe-enter the special charge per spool: ";
            }
            flag = 0;
        }
        else if (choice == 0)
        {
            special_charge = 10;
            flag = 0;
        }
        else
        {
            cout << "Please pick between 1 and 0\nRe-enter choice: ";
        }
    }
}

void output(int number_of_spools_ordered, int number_of_spools_instock, int special_charge = 10)
{

    if (number_of_spools_ordered > number_of_spools_instock)
    {
        cout << "The number of spools ready to ship from current stock: " << number_of_spools_instock << "\nThe number of spools on backorder: " << number_of_spools_ordered - number_of_spools_instock << "\nSubtotal of the portion ready to ship: " << number_of_spools_instock * 100 << "\nTotal shipping and handling charges on the portion ready to ship: " << special_charge * number_of_spools_instock << "\nTotal of the order ready to ship: " << number_of_spools_instock * 100 + special_charge * number_of_spools_instock;
    }
    else
    {
        cout << "The number of spools ready to ship from current stock: " << number_of_spools_ordered << "\nThe number of spools on backorder: 0" << "\nSubtotal of the portion ready to ship: " << number_of_spools_ordered * 100 << "\nTotal shipping and handling charges on the portion ready to ship: " << special_charge * number_of_spools_ordered << "\nTotal of the order ready to ship: " << number_of_spools_ordered * 100 + special_charge * number_of_spools_ordered;
    }
}

int main(int argc, char const *argv[])
{
    int number_of_spools_ordered, number_of_spools_instock, special_charge;
    input(number_of_spools_ordered, number_of_spools_instock, special_charge);
    output(number_of_spools_ordered, number_of_spools_instock, special_charge);
    return 0;
}
