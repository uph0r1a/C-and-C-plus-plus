#include <iostream>
using namespace std;

int Population_per_year(int starting_size, int birth_rate, int death_rate)
{
    return starting_size + birth_rate * starting_size - death_rate * starting_size;
}

int main(int argc, char const *argv[])
{
    int starting_size, birth_rate, death_rate, number_of_year, new_population;

    cout << "Enter the starting size: ";
    while (1)
    {
        cin >> starting_size;
        if (starting_size >= 2)
        {
            new_population = starting_size;
            break;
        }
        cout << "Starting size cannot be less than 2\nRe-enter starting size: ";
    }

    cout << "Enter the birth rate: ";
    while (1)
    {
        cin >> birth_rate;
        if (birth_rate >= 0)
        {
            break;
        }
        cout << "Birth rate cannot be less than 0\nRe-enter birth rate: ";
    }

    cout << "Enter the death rate: ";
    while (1)
    {
        cin >> death_rate;
        if (death_rate >= 0)
        {
            break;
        }
        cout << "Death rate cannot be less than 0\nRe-enter death rate: ";
    }

    cout << "Enter the number of year: ";
    while (1)
    {
        cin >> number_of_year;
        if (number_of_year >= 1)
        {
            break;
        }
        cout << "Number of year cannot be less than 1\nRe-enter number of year: ";
    }

    for (int i = 0; i < number_of_year; i++)
    {
        new_population = Population_per_year(starting_size, birth_rate, death_rate);
        starting_size = new_population;
    }

    cout << "After " << number_of_year << " years, the population is " << new_population;

    return 0;
}
