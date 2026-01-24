#include <iostream>
using namespace std;

class FreezingBoilingPoints
{
public:
    void setTemperature(float t)
    {
        temperature = t;
    }

    float getTemperature() const
    {
        return temperature;
    }

    bool isEthylFreezing() const
    {
        if (temperature < -173)
        {
            return true;
        }
        return false;
    }

    bool isEthylBoiling() const
    {
        if (temperature > 172)
        {
            return true;
        }
        return false;
    }

    bool isOxygenFreezing() const
    {
        if (temperature < -362)
        {
            return true;
        }
        return false;
    }

    bool isOxygenBoiling() const
    {
        if (temperature > -306)
        {
            return true;
        }
        return false;
    }

    bool isWaterFreezing() const
    {
        if (temperature < 32)
        {
            return true;
        }
        return false;
    }

    bool isWaterBoiling() const
    {
        if (temperature > 212)
        {
            return true;
        }
        return false;
    }

private:
    float temperature;
};

int main(int argc, char const *argv[])
{
    FreezingBoilingPoints temperature;
    float tempTemp;

    cout << "Enter temperature: ";
    cin >> tempTemp;
    temperature.setTemperature(tempTemp);

    cout << "At the temperature of " << temperature.getTemperature() << endl;
    if (temperature.isEthylFreezing())
    {
        cout << "Ethyl Alcohol will freeze" << endl;
    }

    if (temperature.isEthylBoiling())
    {
        cout << "Ethyl Alcohol will boil" << endl;
    }

    if (temperature.isOxygenFreezing())
    {
        cout << "Oxygen will freeze" << endl;
    }

    if (temperature.isOxygenBoiling())
    {
        cout << "Oxygen will boil" << endl;
    }

    if (temperature.isWaterFreezing())
    {
        cout << "Water will freeze" << endl;
    }

    if (temperature.isWaterBoiling())
    {
        cout << "Water will boil" << endl;
    }

    if (!temperature.isEthylFreezing() && !temperature.isEthylBoiling() && !temperature.isOxygenFreezing() && !temperature.isOxygenBoiling() && !temperature.isWaterFreezing() && !temperature.isWaterBoiling())
    {
        cout << "Nothing boil or freeze" << endl;
    }

    return 0;
}
