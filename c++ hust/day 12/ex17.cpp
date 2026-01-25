#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class InventoryItem
{
private:
    string description;
    double cost;
    int units;

public:
    InventoryItem()
    {
        description = "";
        cost = 0.0;
        units = 0;
    }

    InventoryItem(string desc)
    {
        description = desc;
        cost = 0.0;
        units = 0;
    }

    InventoryItem(string desc, double c, int u)
    {
        description = desc;
        cost = c;
        units = u;
    }

    void setDescription(string d)
    {
        description = d;
    }

    void setCost(double c)
    {
        cost = c;
    }

    void setUnits(int u)
    {
        units = u;
    }

    string getDescription() const
    {
        return description;
    }

    double getCost() const
    {
        return cost;
    }

    int getUnits() const
    {
        return units;
    }
};

class CashRegister
{
private:
    InventoryItem item;

public:
    void setItemPurchased(string description)
    {
        item.setDescription(description);
    }
};

int main(int argc, char const *argv[])
{
    InventoryItem item1;
    item1.setDescription("Hammer");
    item1.setCost(6.95);
    item1.setUnits(12);

    InventoryItem item2("Pliers");
    InventoryItem item3("Wrench", 8.75, 20);

    cout << "The following items are in inventory:\n";
    cout << setprecision(2) << fixed << showpoint;

    cout << "Description: " << item1.getDescription() << endl;
    cout << "Cost: $" << item1.getCost() << endl;
    cout << "Units on Hand: " << item1.getUnits() << endl
         << endl;

    cout << "Description: " << item2.getDescription() << endl;
    cout << "Cost: $" << item2.getCost() << endl;
    cout << "Units on Hand: " << item2.getUnits() << endl
         << endl;

    cout << "Description: " << item3.getDescription() << endl;
    cout << "Cost: $" << item3.getCost() << endl;
    cout << "Units on Hand: " << item3.getUnits() << endl;

    return 0;
}
