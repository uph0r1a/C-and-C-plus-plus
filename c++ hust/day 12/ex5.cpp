#include <iostream>
#include <string>
using namespace std;

class RetailItem
{
public:
    RetailItem(string descrip, int unit, double p)
    {
        description = descrip;
        unitsOnHand = unit;
        price = p;
    }

    void setDescription(string descrip)
    {
        description = descrip;
    }

    void setUnitsOnHand(int unit)
    {
        unitsOnHand = unit;
    }

    void setPrice(double p)
    {
        price = p;
    }

    string getDescription() const
    {
        return description;
    }

    int getUnitsOnHand() const
    {
        return unitsOnHand;
    }

    double getPrice() const
    {
        return price;
    }

private:
    string description;
    int unitsOnHand;
    double price;
};

int main(int argc, char const *argv[])
{
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    cout << "Item #1" << endl
         << "Description: " << item1.getDescription() << endl
         << "Units On Hand: " << item1.getUnitsOnHand() << endl
         << "Price: " << item1.getPrice() << endl
         << "Item #2" << endl
         << "Description: " << item2.getDescription() << endl
         << "Units On Hand: " << item2.getUnitsOnHand() << endl
         << "Price: " << item2.getPrice() << endl
         << "Item #3" << endl
         << "Description: " << item3.getDescription() << endl
         << "Units On Hand: " << item3.getUnitsOnHand() << endl
         << "Price: " << item3.getPrice() << endl;
    return 0;
}
