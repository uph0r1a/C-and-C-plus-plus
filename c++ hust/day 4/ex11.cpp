#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number_of_organisms, number_of_days;
    float average_daily_population_increase;

    cout << "Enter the starting number of organisms: ";
    while (1)
    {
        cin >> number_of_organisms;
        if (number_of_organisms >= 2)
        {
            break;
        }
        cout << "Do not accept a number less than 2 for the starting size of the population.\n";
        cout << "Re-enter the starting number of organisms: ";
    }

    cout << "Enter their average daily population increase (as a percentage): ";
    while (1)
    {
        cin >> average_daily_population_increase;
        if (average_daily_population_increase >= 0)
        {
            break;
        }
        cout << "Do not accept a negative number for average daily population increase.\n";
        cout << "Re-enter their average daily population increase (as a percentage): ";
    }

    cout << "Enter the number of days they will multiply: ";
    while (1)
    {
        cin >> number_of_days;
        if (number_of_days >= 1)
        {
            break;
        }
        cout << "Do not accept a number less than 1 for the number of days they will multiply.\n";
        cout << "Re-enter the number of days they will multiply: ";
    }

    for (int i = 1; i <= number_of_days; i++)
    {
        number_of_organisms += number_of_organisms * (average_daily_population_increase / 100);
        cout << "The size of the population for day " << i << ": " << number_of_organisms << "\n";
    }

    return 0;
}
