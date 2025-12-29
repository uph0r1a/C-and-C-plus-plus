#include <iostream>
#include <cmath>
using namespace std;

struct MonthlyBudget
{
     float Housing = 500.00, Utilities = 150.00, HouseholdExpenses = 65.00, Transportation = 50.00, Food = 250.00, Medical = 30.00, Insurance = 100.00, Entertainment = 150.00, Clothing = 75.00, Miscellaneous = 50.00;
};

void inputValidation(float &number)
{
     while (1)
     {
          cin >> number;
          if (number >= 0)
          {
               break;
          }
          cout << "Budget cannot be negative\nRe-enter the expense: ";
     }
}

void input(MonthlyBudget &amountSpent)
{
     cout << "Enter the housing amount spent: ";
     inputValidation(amountSpent.Housing);

     cout << "Enter the utilities amount spent: ";
     inputValidation(amountSpent.Utilities);

     cout << "Enter the household expenses amount spent: ";
     inputValidation(amountSpent.HouseholdExpenses);

     cout << "Enter the transportation amount spent: ";
     inputValidation(amountSpent.Transportation);

     cout << "Enter the food amount spent: ";
     inputValidation(amountSpent.Food);

     cout << "Enter the medical amount spent: ";
     inputValidation(amountSpent.Medical);

     cout << "Enter the insurance amount spent: ";
     inputValidation(amountSpent.Insurance);

     cout << "Enter the entertainment amount spent: ";
     inputValidation(amountSpent.Entertainment);

     cout << "Enter the clothing amount spent: ";
     inputValidation(amountSpent.Clothing);

     cout << "Enter the miscellaneous amount spent: ";
     inputValidation(amountSpent.Miscellaneous);
}

void outputCase(float spent, float budget)
{
     cout << (spent > budget ? "Overbudget: " : "Underbudget: ")
          << abs(spent - budget);
}

void output(MonthlyBudget budget, MonthlyBudget amountSpent)
{
     cout << "Housing: ";
     outputCase(amountSpent.Housing, budget.Housing);
     cout << endl
          << "Utilities: ";
     outputCase(amountSpent.Utilities, budget.Utilities);
     cout << endl
          << "HouseholdExpenses: ";
     outputCase(amountSpent.HouseholdExpenses, budget.HouseholdExpenses);
     cout << endl
          << "Transportation: ";
     outputCase(amountSpent.Transportation, budget.Transportation);
     cout << endl
          << "Food: ";
     outputCase(amountSpent.Food, budget.Food);
     cout << endl
          << "Medical: ";
     outputCase(amountSpent.Medical, budget.Medical);
     cout << endl
          << "Insurance: ";
     outputCase(amountSpent.Insurance, budget.Insurance);
     cout << endl
          << "Entertainment: ";
     outputCase(amountSpent.Entertainment, budget.Entertainment);
     cout << endl
          << "Clothing: ";
     outputCase(amountSpent.Clothing, budget.Clothing);
     cout << endl
          << "Miscellaneous: ";
     outputCase(amountSpent.Miscellaneous, budget.Miscellaneous);
}

int main(int argc, char const *argv[])
{
     MonthlyBudget budget, amountSpent;

     input(amountSpent);
     output(budget, amountSpent);
     return 0;
}
