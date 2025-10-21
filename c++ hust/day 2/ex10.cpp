#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float replacement_cost;
    cout << "Enter the replacement cost of a building: ";
    cin >> replacement_cost;
    cout << "The minimum amount of insurance you should buy for the property: " << replacement_cost * 0.8;
    return 0;
}
