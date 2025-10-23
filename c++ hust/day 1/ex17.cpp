#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float total_stock = 750, price_per_share = 35;
    cout << "The amount paid for the stock alone (without the commission): " << total_stock * price_per_share << "\n"
         << "The amount of the commission: " << (total_stock * price_per_share) * 0.02 << "\n"
         << "The total amount paid (for the stock plus the commission): " << (total_stock * price_per_share) + (total_stock * price_per_share) * 0.02 << endl;
    return 0;
}
