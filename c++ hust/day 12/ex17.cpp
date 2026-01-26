#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryItem
{
private:
    string description;
    double cost;
    int onHand;

public:
    InventoryItem(string d = "", double c = 0.0, int o = 0)
    {
        description = d;
        cost = c;
        onHand = o;
    }

    string getDescription() const { return description; }
    double getCost() const { return cost; }
    int getOnHand() const { return onHand; }

    void reduceOnHand(int qty)
    {
        onHand -= qty;
    }
};

class CashRegister
{
private:
    InventoryItem &item;
    int quantity;

public:
    CashRegister(InventoryItem &i, int q)
        : item(i), quantity(q) {}

    double getUnitPrice() const
    {
        return item.getCost() * 1.30;
    }

    double getSubtotal() const
    {
        return getUnitPrice() * quantity;
    }

    double getTax() const
    {
        return getSubtotal() * 0.06;
    }

    double getTotal() const
    {
        return getSubtotal() + getTax();
    }

    void processSale()
    {
        item.reduceOnHand(quantity);
    }
};

int main(int argc, char const *argv[])
{
    cout << fixed << setprecision(2);

    const int SIZE = 3;

    InventoryItem inventory[SIZE] =
        {
            InventoryItem("Hammer", 6.95, 12),
            InventoryItem("Pliers", 5.50, 10),
            InventoryItem("Wrench", 8.75, 20)};

    int choice;
    char again;

    do
    {
        cout << "\n===== INVENTORY MENU =====\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout << i + 1 << ". "
                 << inventory[i].getDescription()
                 << " ($" << inventory[i].getCost()
                 << ", On Hand: " << inventory[i].getOnHand()
                 << ")\n";
        }
        cout << "0. Exit\n";

        do
        {
            cout << "\nSelect an item: ";
            cin >> choice;
        } while (choice < 0 || choice > SIZE);

        if (choice == 0)
            break;

        InventoryItem &selectedItem = inventory[choice - 1];
        int quantity;

        do
        {
            cout << "Enter quantity to purchase: ";
            cin >> quantity;

            if (quantity < 0)
                cout << "Quantity cannot be negative.\n";
            else if (quantity > selectedItem.getOnHand())
                cout << "Not enough items in stock.\n";

        } while (quantity < 0 || quantity > selectedItem.getOnHand());

        CashRegister sale(selectedItem, quantity);

        cout << "\n----- RECEIPT -----\n";
        cout << "Item: " << selectedItem.getDescription() << endl;
        cout << "Subtotal: $" << sale.getSubtotal() << endl;
        cout << "Tax: $" << sale.getTax() << endl;
        cout << "Total: $" << sale.getTotal() << endl;

        sale.processSale();

        cout << "Remaining units: "
             << selectedItem.getOnHand() << endl;

        cout << "\nMake another purchase? (y/n): ";
        cin >> again;

    } while (tolower(again) == 'y');

    cout << "\nThank you for shopping!\n";

    return 0;
}
