#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float class_A = 15, class_B = 12, class_C = 9, class_A_sold, class_B_sold, class_C_sold, income;
    cout << " How many tickets sold for class A: ";
    cin >> class_A_sold;
    cout << " How many tickets sold for class B: ";
    cin >> class_B_sold;
    cout << " How many tickets sold for class C: ";
    cin >> class_C_sold;

    income = class_A * class_A_sold + class_B * class_B_sold + class_C * class_C_sold;
    cout << "$" << fixed << setprecision(2) << showpoint << income;
    return 0;
}
