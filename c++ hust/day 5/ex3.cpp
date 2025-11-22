#include <iostream>
#include <string>
using namespace std;

double getSales(string name)
{
    double quarterly_sales;
    cout << "Enter the " << name << " division's quarterly sales figure: ";
    while (1)
    {
        cin >> quarterly_sales;
        if (quarterly_sales >= 0)
        {
            break;
        }
        cout << "Division's quarterly sales figure cannot be less than $0.00\nRe-enter the " << name << " division's quarterly sales figure: ";
    }

    return quarterly_sales;
}

void findHighest(double northeast, double southeast, double northwest, double southwest)
{
    double max = northeast;
    string division_max = "Northeast";
    if (southeast > max)
    {
        max = southeast;
        division_max = "Southeast";
    }
    if (northwest > max)
    {
        max = northwest;
        division_max = "Northwest";
    }
    if (southwest > max)
    {
        max = southwest;
        division_max = "Southwest";
    }

    cout << "Highest grossing division: " << division_max << "\nSales: " << max;
}

int main(int argc, char const *argv[])
{
    double northeast, southeast, northwest, southwest;

    northeast = getSales("Northeast");
    southeast = getSales("Southeast");
    northwest = getSales("Northwest");
    southwest = getSales("Southwest");

    findHighest(northeast, southeast, northwest, southwest);

    return 0;
}
