#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float sales[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter today's sales for store " << i + 1 << ": ";
        cin >> sales[i];
    }

    cout << "SALES BAR CHART\n"
         << "(Each * = $100)" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Store " << i + 1 << ": ";
        for (int j = 0; j < sales[i] / 100; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}