#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int retail = 99, quantity;
    cout << "Enter the number of units sold: ";
    cin >> quantity;
    if (quantity <= 0)
    {
        cout << "The number of units is greater than 0";
    }
    else if (quantity > 0 && quantity < 10)
    {
        cout << "The total cost of the purchase: " << retail * quantity;
    }
    else if (quantity >= 10 && quantity <= 19)
    {
        cout << "The total cost of the purchase: " << (retail * quantity) * 0.2;
    }
    else if (quantity >= 20 && quantity <= 49)
    {
        cout << "The total cost of the purchase: " << (retail * quantity) * 0.3;
    }
    else if (quantity >= 50 && quantity <= 99)
    {
        cout << "The total cost of the purchase: " << (retail * quantity) * 0.4;
    }
    else
    {
        cout << "The total cost of the purchase: " << (retail * quantity) * 0.5;
    }

    return 0;
}
