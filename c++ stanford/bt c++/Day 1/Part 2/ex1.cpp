#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double cm;
    do
    {
        cout << "Nhap chieu dai (cm > 0): ";
        cin >> cm;
    } while (cm <= 0);

    double inch = cm / 2.54;
    double foot = inch / 12.0;

    cout << fixed << setprecision(2);
    cout << cm << " cm = " << inch << " inches\n";
    cout << cm << " cm = " << foot << " feet\n";
    return 0;
}
