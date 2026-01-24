#include <iostream>
using namespace std;

class Inventory
{
public:
    Inventory()
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
    }

    Inventory(int number, double c, int quan)
    {
        itemNumber = number;
        cost = c;
        quantity = quan;
        setTotalCost();
    }

    void setItemNumber(int number)
    {
        itemNumber = number;
    }

    void setQuantity(int quan)
    {
        quantity = quan;
    }

    void setCost(int c)
    {
        cost = c;
    }

    void setTotalCost()
    {
        totalCost = quantity * cost;
    }

    int getItemNumber() const
    {
        return itemNumber;
    }

    int getQuantity() const
    {
        return quantity;
    }

    int getCost() const
    {
        return cost;
    }

    int getTotalCost() const
    {
        return totalCost;
    }

private:
    int itemNumber, quantity;
    double cost, totalCost;
};

int main(int argc, char const *argv[])
{
    Inventory inventory;
    int tempItemNumber, tempQuantity;
    double tempCost;

    cout << "Enter item number: ";
    while (1)
    {
        cin >> tempItemNumber;
        if (tempItemNumber >= 0)
        {
            inventory.setItemNumber(tempItemNumber);
            break;
        }
        cout << "Item number must not be negative\nRe-enter item number: ";
    }

    cout << "Enter quantity: ";
    while (1)
    {
        cin >> tempQuantity;
        if (tempQuantity >= 0)
        {
            inventory.setQuantity(tempQuantity);
            break;
        }
        cout << "Quantity must not be negative\nRe-enter quantity: ";
    }

    cout << "Enter cost: ";
    while (1)
    {
        cin >> tempCost;
        if (tempCost >= 0)
        {
            inventory.setCost(tempCost);
            break;
        }
        cout << "Cost must not be negative\nRe-enter cost: ";
    }

    inventory.setTotalCost();

    cout << "Item number: " << inventory.getItemNumber() << endl
         << "Quantity: " << inventory.getQuantity() << endl
         << "Cost: " << inventory.getCost() << endl
         << "Total cost: " << inventory.getTotalCost() << endl;

    return 0;
}
