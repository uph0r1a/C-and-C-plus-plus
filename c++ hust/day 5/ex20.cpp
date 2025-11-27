#include <iostream>
using namespace std;

void Profit(float number_of_shares, float purchase_price_per_share, float purchase_commission_paid, float sale_price_per_share, float sale_commission_paid)
{
    float calc = ((number_of_shares * sale_price_per_share) - sale_commission_paid) - ((number_of_shares * purchase_price_per_share) + purchase_commission_paid);
    if (calc >= 0)
    {
        cout << "Profit: " << calc;
    }
    else
    {
        cout << "Loss: " << 0 - calc;
    }
}

int main(int argc, char const *argv[])
{
    float number_of_shares, purchase_price_per_share, purchase_commission_paid, sale_price_per_share, sale_commission_paid;
    cout << "Enter the number of shares: ";
    while (1)
    {
        cin >> number_of_shares;
        if (number_of_shares >= 0)
        {
            break;
        }
        cout << "Number of shares cannot be negative\nRe-enter the number of shares: ";
    }

    cout << "Enter the purchase price per share: ";
    while (1)
    {
        cin >> purchase_price_per_share;
        if (purchase_price_per_share >= 0)
        {
            break;
        }
        cout << "Purchase price per share cannot be negative\nRe-enter the urchase price per share: ";
    }

    cout << "Enter the purchase commission paid: ";
    while (1)
    {
        cin >> purchase_commission_paid;
        if (purchase_commission_paid >= 0)
        {
            break;
        }
        cout << "Purchase commission paid cannot be negative\nRe-enter the purchase commission paid: ";
    }

    cout << "Enter the sale price per share: ";
    while (1)
    {
        cin >> sale_price_per_share;
        if (sale_price_per_share >= 0)
        {
            break;
        }
        cout << "Sale price per share cannot be negative\nRe-enter the sale price per share: ";
    }

    cout << "Enter the sale commission paid: ";
    while (1)
    {
        cin >> sale_commission_paid;
        if (sale_commission_paid >= 0)
        {
            break;
        }
        cout << "Sale commission paid cannot be negative\nRe-enter the sale commission paid: ";
    }

    Profit(number_of_shares, purchase_price_per_share, purchase_commission_paid, sale_price_per_share, sale_commission_paid);

    return 0;
}
