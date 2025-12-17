#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    string divisionName;
    float firstQuarterSales, secondQuarterSales, thirdQuarterSales, fourthQuarterSales, totalAnnualSales, averageQuarterlySales;
} CompanyDivision;

void inputQuarterSale(string name, float &quarterSale)
{
    while (1)
    {
        cin >> quarterSale;
        if (quarterSale >= 0)
        {
            break;
        }
        cout << "The " << name << " division quarter sales cannot be negative\nRe-enter the " << name << " division quarter sales: ";
    }
}

void companyDivision(CompanyDivision company[4])
{
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            company[i].divisionName = "East";
            break;
        case 1:
            company[i].divisionName = "West";
            break;
        case 2:
            company[i].divisionName = "North";
            break;
        case 3:
            company[i].divisionName = "South";
            break;
        default:
            break;
        }

        cout << company[i].divisionName << ": " << endl;
        cout << "Enter the " << company[i].divisionName << " division first quarter sales: ";
        inputQuarterSale(company[i].divisionName, company[i].firstQuarterSales);

        cout << "Enter the " << company[i].divisionName << " division second quarter sales: ";
        inputQuarterSale(company[i].divisionName, company[i].secondQuarterSales);

        cout << "Enter the " << company[i].divisionName << " division third quarter sales: ";
        inputQuarterSale(company[i].divisionName, company[i].thirdQuarterSales);

        cout << "Enter the " << company[i].divisionName << " division fourth quarter sales: ";
        inputQuarterSale(company[i].divisionName, company[i].fourthQuarterSales);

        company[i].totalAnnualSales = company[i].firstQuarterSales + company[i].secondQuarterSales + company[i].thirdQuarterSales + company[i].fourthQuarterSales;

        company[i].averageQuarterlySales = (company[i].totalAnnualSales) / 4;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << endl
             << "Division " << company[i].divisionName << endl
             << "First quarter sales: " << company[i].firstQuarterSales << endl
             << "Second quarter sales: " << company[i].secondQuarterSales << endl
             << "Third quarter sales: " << company[i].thirdQuarterSales << endl
             << "Fourth quarter sales: " << company[i].fourthQuarterSales << endl
             << "Total annual sales: " << company[i].totalAnnualSales << endl
             << "Average quarterly sales: " << company[i].averageQuarterlySales << endl;
    }
}

int main(int argc, char const *argv[])
{
    CompanyDivision company[4];

    companyDivision(company);
    return 0;
}
