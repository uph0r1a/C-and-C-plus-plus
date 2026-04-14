#include <iostream>
#include <string>
using namespace std;

class Ship
{
private:
    string shipName, yearShipBuild;

public:
    Ship(string name, string year)
        : shipName(name),
          yearShipBuild(year) {}

    void setShipName(string name)
    {
        shipName = name;
    }

    void setYearShipBuild(string year)
    {
        yearShipBuild = year;
    }

    string getShipName() const
    {
        return shipName;
    }

    string getYearShipBuild() const
    {
        return yearShipBuild;
    }

    virtual void print()
    {
        cout << "Ship name: " << shipName << endl
             << "Year that the ship was build: " << yearShipBuild << endl;
    }
};

class CruiseShip : public Ship
{
private:
    int maxPassenger;

public:
    CruiseShip(string name, string year, int max)
        : Ship(name, year),
          maxPassenger(max) {}

    void setMaxPassenger(int max)
    {
        maxPassenger = max;
    }

    int getMaxPassenger() const
    {
        return maxPassenger;
    }

    void print() override
    {
        cout << "Ship name: " << getShipName() << endl
             << "Maximum number of passengers: " << maxPassenger << endl;
    }
};

class CargoShip : public Ship
{
private:
    int cargoCapacity;

public:
    CargoShip(string name, string year, int capacity)
        : Ship(name, year),
          cargoCapacity(capacity) {}

    void setCargoCapacity(int capacity)
    {
        cargoCapacity = capacity;
    }

    int getCargoCapacity() const
    {
        return cargoCapacity;
    }

    void print() override
    {
        cout << "Ship name: " << getShipName() << endl
             << "Cargo capacity in tonnage: " << cargoCapacity << endl;
    }
};

void print(const Ship *);

int main(int argc, char const *argv[])
{
    Ship *ship[3] = {
        new Ship("Ship name", "2000"),
        new CruiseShip("Cruise ship name", "2001", 1000),
        new CargoShip("Cargo ship name", "2002", 500)};

    for (int i = 0; i < 3; i++)
    {
        ship[i]->print();
        cout << endl;
        delete ship[i];
    }

    return 0;
}
