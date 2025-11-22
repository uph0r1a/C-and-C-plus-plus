#include <iostream>
using namespace std;

float calculateRetail(float wholesale_cost, float markup_percentage)
{
    cout << "Enter an item's wholesale cost: ";
    while (1)
    {
        cin >> wholesale_cost;
        if (wholesale_cost >= 0)
        {
            break;
        }
        cout << "The wholesale cost of the item cannot be nagetive\nRe-enter the wholesale cost of the item: ";
    }

    cout << "Enter an item's markup percentage: ";
    while (1)
    {
        cin >> markup_percentage;
        if (markup_percentage >= 0)
        {
            break;
        }
        cout << "The markup percentage of the item cannot be nagetive\nRe-enter the markup percentage of the item: ";
    }

    return wholesale_cost + wholesale_cost * (markup_percentage / 100);
}

int main(int argc, char const *argv[])
{
    float wholesale_cost, markup_percentage, retail_price = calculateRetail(wholesale_cost, markup_percentage);

    cout << "Retail price: " << retail_price;

    return 0;
}
