#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const double PI = acos(-1.0);
    double R;

    do
    {
        cout << "Nhap ban kinh R (> 0): ";
        cin >> R;
    } while (R <= 0);

    double dienTich = 4.0 * PI * R * R;
    double theTich = (4.0 / 3.0) * PI * R * R * R;

    cout << fixed << setprecision(2);
    cout << "Dien tich be mat = " << dienTich << "\n";
    cout << "The tich = " << theTich << "\n";
    return 0;
}
