#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float price = 95, state_tax = 0.04, county_tax = 0.02, total = price + price * (state_tax + county_tax);

    cout << "$" << total << endl;
    return 0;
}
