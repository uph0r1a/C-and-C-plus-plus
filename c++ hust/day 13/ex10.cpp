#include <iostream>
using namespace std;

class DivSales
{
private:
    static float totalSales;

public:
    float quartersSales[4];

    void setTotalSales(float quarter1, float quarter2, float quarter3, float quarter4)
    {
        quartersSales[0] = quarter1;
        quartersSales[1] = quarter2;
        quartersSales[2] = quarter3;
        quartersSales[3] = quarter4;

        totalSales += quarter1 + quarter2 + quarter3 + quarter4;
    }

    float getQuarterSales(int i) const
    {
        if (i >= 0 && i <= 3)
        {
            return quartersSales[i];
        }
        else
        {
            return 0;
        }
    }

    static float getTotalSales()
    {
        return totalSales;
    }
};
float DivSales::totalSales = 0;

int main(int argc, char const *argv[])
{
    DivSales div[6];

    for (int i = 0; i < 6; i++)
    {
        cout << "Division " << i + 1 << endl;
        float tempQuarter[4];
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter division " << i + 1 << " quarter " << j + 1 << " sales: ";
            while (1)
            {
                cin >> tempQuarter[j];
                if (tempQuarter[j] >= 0)
                {
                    break;
                }
                cout << "Quarterly sale cannot be negative\nRe-enter division " << i + 1 << " quarter " << j + 1 << " sales: ";
            }
        }
        div[i].setTotalSales(tempQuarter[0], tempQuarter[1], tempQuarter[2], tempQuarter[3]);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << "Division " << i + 1 << endl;
        for (int j = 0; j < 4; j++)
        {
            cout << "Quarter " << j + 1 << ": " << div[i].getQuarterSales(j) << endl;
        }
    }

    cout << "Total coporate sales: " << DivSales::getTotalSales() << endl;

    return 0;
}
