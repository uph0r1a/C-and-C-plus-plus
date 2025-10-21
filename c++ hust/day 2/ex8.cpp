#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float pallet_weight, pallet_weight_with_widgets;
    cout << "How much the pallet weighs by itself: ";
    cin >> pallet_weight;
    cout << "how much the pallet weighs with the widgets stacked on it: ";
    cin >> pallet_weight_with_widgets;
    cout << "Number of widgets stacked on the pallet: " << (pallet_weight_with_widgets - pallet_weight) / 12.5 << endl;
    return 0;
}
