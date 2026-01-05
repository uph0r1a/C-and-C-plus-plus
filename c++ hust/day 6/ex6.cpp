#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void Rain_or_shine()
{

    ifstream f1("files/RainOrShine.txt");

    if (!f1)
    {
        cout << "Cannot open file";
        return;
    }

    string maxrainMonth;
    char day[3][30];
    int rainy[3] = {0}, cloudy[3] = {0}, sunny[3] = {0}, totalraindays = 0, totalcloudday = 0, totalsunday = 0, max, maxmonth;

    string line;
    int i = 0;
    while (getline(f1, line))
    {
        for (int j = 0; j < 30; j++)
        {
            day[i][j] = line[j];
            if (toupper(day[i][j]) == 'R')
            {
                rainy[i]++;
            }
            else if (toupper(day[i][j]) == 'C')
            {
                cloudy[i]++;
            }
            else
            {
                sunny[i]++;
            }
        }
        totalraindays += rainy[i];
        totalcloudday += cloudy[i];
        totalsunday += sunny[i];
        i++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            max = rainy[i];
            maxmonth = i;
        }
        if (rainy[i] > max)
        {
            max = rainy[i];
            maxmonth = i;
        }
    }

    if (maxmonth == 0)
    {
        maxrainMonth = "June";
    }
    else if (maxmonth == 1)
    {
        maxrainMonth = "July";
    }
    else
    {
        maxrainMonth = "August";
    }

    ofstream f2("files/RainOrShineoutput.txt");

    if (!f2)
    {
        cout << "Cannot open file";
        return;
    }

    f2 << "June: " << endl
       << "Rainy day: " << rainy[0] << endl
       << "Cloudy day: " << cloudy[0] << endl
       << "Sunny day: " << sunny[0] << endl
       << "July:" << endl
       << "Rainy day: " << rainy[1] << endl
       << "Cloudy day: " << cloudy[1] << endl
       << "Sunny day: " << sunny[1] << endl
       << "August:" << endl
       << "Rainy day: " << rainy[2] << endl
       << "Cloudy day: " << cloudy[2] << endl
       << "Sunny day: " << sunny[2] << endl
       << "Whole 3 months: " << endl
       << "Rainy day: " << totalraindays << endl
       << "Cloudy day: " << totalcloudday << endl
       << "Sunny day: " << totalsunday << endl
       << "Months had the largest number of rainy days: " << maxrainMonth;
    f1.close();
    f2.close();
}

int main(int argc, char const *argv[])
{
    Rain_or_shine();
    return 0;
}
