#include <iostream>
#include <string>
using namespace std;

void Salsa()
{
    const int number = 5;
    string name[number] = {"mild", "medium", "sweet", "hot", "zesty"}, maxName, minName;
    int jar_sold[number], max, min, sum = 0;
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the number of jars sold for " << name[i] << ": ";
        while (1)
        {
            cin >> jar_sold[i];
            if (jar_sold[i] >= 0)
            {
                break;
            }
            cout << "Number of jars sold cannot be negative\nRe-enter the number of jars sold for " << name[i] << ": ";
        }
        if (i == 0)
        {
            max = jar_sold[i];
            min = jar_sold[i];
            maxName = name[i];
            minName = name[i];
        }
        if (jar_sold[i] > max)
        {
            max = jar_sold[i];
            maxName = name[i];
        }
        if (jar_sold[i] < min)
        {
            min = jar_sold[i];
            minName = name[i];
        }
        sum += jar_sold[i];
    }
    for (int i = 0; i < number; i++)
    {
        cout << name[i] << ": " << jar_sold[i] << endl;
    }
    cout << "Total sales: " << sum << endl
         << "Names of the highest selling: " << maxName << endl
         << "Names of the lowest selling: " << minName;
}

int main(int argc, char const *argv[])
{
    Salsa();
    return 0;
}
