#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float budget, expenses, total = 0;
    int number_of_expenses;
    cout << "Enter budget: ";
    while (1)
    {
        cin >> budget;
        if (budget > 0)
        {
            break;
        }
        cout << "Budget cannot be less than 0\n";
        cout << "Re-enter budget: ";
    }

    cout << "Enter number of expenses: ";
    while (1)
    {
        cin >> number_of_expenses;
        if (number_of_expenses > 0)
        {
            break;
        }
        cout << "Number of expenses cannot be less than 0\n";
        cout << "Re-enter number of expenses: ";
    }

    for (int i = 0; i < number_of_expenses; i++)
    {
        cout << "Enter your expenses: ";
        cin >> expenses;
        total += expenses;
    }

    if (total > budget)
    {
        cout << "You are over budget $" << total - budget << endl;
    }
    else
    {
        cout << "You are under budget $" << budget - total << endl;
    }

    return 0;
}