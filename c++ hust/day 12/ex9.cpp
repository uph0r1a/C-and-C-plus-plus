#include <iostream>
using namespace std;

class Population
{
public:
    Population()
    {
        population = 0;
        numberOfBirths = 0;
        numberOfDeaths = 0;
    }

    void setPopulation(int pop)
    {
        population = pop;
    }

    void setNumberOfBirths(int birth)
    {
        numberOfBirths = birth;
    }

    void setNumberOfDeaths(int death)
    {
        numberOfDeaths = death;
    }

    float getBirthRate() const
    {
        if (population > 0)
        {
            return static_cast<float>(numberOfBirths) / population;
        }
        return 0;
    }

    float getDeathRate() const
    {
        if (population > 0)
        {
            return static_cast<float>(numberOfDeaths) / population;
        }
        return 0;
    }

private:
    int population, numberOfBirths, numberOfDeaths;
};

int main(int argc, char const *argv[])
{
    Population population;
    int tempPopulation, tempBirth, tempDeath;

    cout << "Enter the population: ";
    while (1)
    {
        cin >> tempPopulation;
        if (tempPopulation >= 1)
        {
            population.setPopulation(tempPopulation);
            break;
        }
        cout << "Population cannot be less than 1\nRe-enter population: ";
    }

    cout << "Enter the number of births: ";
    while (1)
    {
        cin >> tempBirth;
        if (tempBirth >= 0)
        {
            population.setNumberOfBirths(tempBirth);
            break;
        }
        cout << "Number of births cannot be less than 0\nRe-enter number of birth: ";
    }

    cout << "Enter the number of deaths: ";
    while (1)
    {
        cin >> tempDeath;
        if (tempDeath >= 0)
        {
            population.setNumberOfDeaths(tempDeath);
            break;
        }
        cout << "Number of deaths cannot be less than 0\nRe-enter number of deaths: ";
    }

    cout << "Birth rate: " << population.getBirthRate() << endl
         << "Death rate: " << population.getDeathRate() << endl;

    return 0;
}
