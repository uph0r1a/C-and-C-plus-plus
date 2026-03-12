#include <iostream>
using namespace std;

class FuelGauge
{
private:
    int amountFuel;

public:
    FuelGauge(int amount = 0) : amountFuel(amount) {}

    int getAmountFuel() const
    {
        return amountFuel;
    }

    FuelGauge operator++(int)
    {
        FuelGauge temp = *this;
        if (amountFuel < 15)
            amountFuel++;
        return temp;
    }

    FuelGauge operator--(int)
    {
        FuelGauge temp = *this;
        if (amountFuel > 0)
            amountFuel--;
        return temp;
    }
};

class Odometer
{
private:
    int currentMileage;
    int milesSinceFuel;

public:
    Odometer(int mileage = 0)
    {
        currentMileage = mileage;
        milesSinceFuel = 0;
    }

    int getCurrentMileage() const
    {
        return currentMileage;
    }

    void operator++(int)
    {
        currentMileage++;

        if (currentMileage > 999999)
            currentMileage = 0;

        milesSinceFuel++;
    }

    void burnFuel(FuelGauge &fuel)
    {
        if (milesSinceFuel == 24)
        {
            fuel--;
            milesSinceFuel = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    FuelGauge fuel(0);
    Odometer odo(0);

    for (int i = 0; i < 15; i++)
        fuel++;

    while (fuel.getAmountFuel() > 0)
    {
        odo++;
        odo.burnFuel(fuel);

        cout << "Mileage: " << odo.getCurrentMileage()
             << " | Fuel: " << fuel.getAmountFuel() << endl;
    }

    cout << "Out of fuel!\n";

    return 0;
}