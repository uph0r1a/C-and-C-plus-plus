#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    char month[10];
    int year;
    float total_collected;

    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter total amount collected at the cash register: ";
    cin >> total_collected;

    cout << "Month: " << month << "\n"
         << "--------------------" << "\n"
         << "Total Collected:" << setw(10) << "$ " << total_collected << "\n"
         << "Sales:" << setw(20) << "$ " << total_collected / 1.06 << "\n"
         << "County Sales Tax:" << setw(8) << "$   " << (total_collected / 1.06) * 0.02 << "\n"
         << "State Sales Tax:" << setw(11) << "$ " << (total_collected / 1.06) * 0.04 << "\n"
         << "Total Sales Tax:" << setw(11) << "$ " << (total_collected / 1.06) * 0.06 << endl;
    return 0;
}
