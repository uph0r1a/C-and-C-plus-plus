#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float shares_purchased = 1000, purchased_amount_per_share = 45.5, purchased_commision_percentage = 0.02, shares_sold = 1000, sold_amount_per_share = 56.9, sold_commision_percentage = 0.02;

    cout << "The amount of money Joe paid for the stock: " << shares_purchased * purchased_amount_per_share << "\n"
         << "The amount of commission Joe paid his broker when he bought the stock: " << (shares_purchased * purchased_amount_per_share) * purchased_commision_percentage << "\n"
         << "The amount that Joe sold the stock for: " << shares_sold * sold_amount_per_share << "\n"
         << "The amount of commission Joe paid his broker when he sold the stock: " << (shares_sold * sold_amount_per_share) * sold_commision_percentage << "\n"
         << "The amount of profit that Joe made after selling his stock and paying the two commissions to his broker: " << ((shares_sold * sold_amount_per_share) * sold_commision_percentage - shares_sold * sold_amount_per_share) - ((shares_purchased * purchased_amount_per_share) * purchased_commision_percentage - shares_purchased * purchased_amount_per_share) << endl;
    if (((shares_sold * sold_amount_per_share) * sold_commision_percentage - shares_sold * sold_amount_per_share) - ((shares_purchased * purchased_amount_per_share) * purchased_commision_percentage - shares_purchased * purchased_amount_per_share) < 0)
    {
        cout << "Joe lost money on the transaction";
    }

    return 0;
}
