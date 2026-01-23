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
        if (number >= 0)
        {
            itemNumber = number;
        }
    }

    void setQuantity(int quan)
    {
        if (quan >= 0)
        {
            quantity = quan;
        }
    }

    void setCost(int c)
    {
        if (c >= 0)
        {
            cost = c;
        }
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
    inventory.setItemNumber(1);
    inventory.setQuantity(2);
    inventory.setCost(2);
    inventory.setTotalCost();

    cout << "Item number: " << inventory.getItemNumber() << endl
         << "Quantity: " << inventory.getQuantity() << endl
         << "Cost: " << inventory.getCost() << endl
         << "Total cost: " << inventory.getTotalCost() << endl;

    return 0;
}
