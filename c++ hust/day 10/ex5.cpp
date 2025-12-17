#include <iostream>
using namespace std;

enum Month
{
    JANUARY = 0,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER,
    TOTAL_MONTH
};

typedef struct
{
    float totalRainfall, highTemperature, lowTemperature, averageTemperature;
} WeatherPerMonth;

void inputTemp(int month, float &temp)
{
    while (1)
    {
        cin >> temp;
        if (temp >= -100 && temp <= 140)
        {
            break;
        }
        cout << "The temperature of month " << month << " must be between -100 and +140 degrees Fahrenheit\nRe-enter the temperature: ";
    }
}

void WeatherStatistic(WeatherPerMonth weather[TOTAL_MONTH])
{
    float totalRainfall = 0, maxTemp = -100, minTemp = 140, maxTempMonth, minTempMonth, totalAverageTemp = 0;
    for (Month i = JANUARY; i < TOTAL_MONTH; i = static_cast<Month>(i + 1))
    {
        cout << "Month " << i + 1 << endl;
        cout << "Enter the total rainfall of month " << i + 1 << ": ";
        while (1)
        {
            cin >> weather[i].totalRainfall;
            if (weather[i].totalRainfall >= 0)
            {
                totalRainfall += weather[i].totalRainfall;
                break;
            }
            cout << "Total rainfall cannot be negative\nRe-enter the total rainfall of month " << i + 1 << ": ";
        }

        cout << "Enter the high temperature of month " << i + 1 << ": ";
        inputTemp(i + 1, weather[i].highTemperature);

        if (weather[i].highTemperature >= maxTemp)
        {
            maxTemp = weather[i].highTemperature;
            maxTempMonth = i + 1;
        }

        cout << "Enter the low temperature of month " << i + 1 << ": ";
        inputTemp(i + 1, weather[i].lowTemperature);

        if (weather[i].lowTemperature <= minTemp)
        {
            minTemp = weather[i].lowTemperature;
            minTempMonth = i + 1;
        }

        weather[i].averageTemperature = (weather[i].highTemperature + weather[i].lowTemperature) / 2;
        totalAverageTemp += weather[i].averageTemperature;
    }

    for (Month i = JANUARY; i < TOTAL_MONTH; i = static_cast<Month>(i + 1))
    {
        cout << "Average monthly rainfall: " << totalRainfall / 12 << endl
             << "Total rainfall for the year: " << totalRainfall << endl
             << "Highest temperatures for the year: " << maxTemp << " in month " << maxTempMonth << endl
             << "Lowest temperatures for the year: " << minTemp << " in month " << minTempMonth << endl
             << "Average of all the monthly average temperatures: " << totalAverageTemp / 12 << endl;
    }
}

int main(int argc, char const *argv[])
{
    WeatherPerMonth weather[TOTAL_MONTH];

    WeatherStatistic(weather);
    return 0;
}
