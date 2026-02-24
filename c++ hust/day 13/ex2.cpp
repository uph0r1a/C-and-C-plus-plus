#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
    int number;

public:
    DayOfYear(int num)
    {
        number = num;
    }

    string print() const
    {
        int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string monthStr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        int temp = number;
        int i = 0;
        while (i < 12 && temp > dayInMonth[i])
        {
            temp -= dayInMonth[i];
            i++;
        }

        return "Day " + to_string(number) + " would be " + monthStr[i] + " " + to_string(temp);
    }
};

int main(int argc, char const *argv[])
{
    int tempNum;
    cout << "Enter the day of the year: ";
    while (1)
    {
        cin >> tempNum;
        if (tempNum > 0 && tempNum <= 365)
        {
            break;
        }
        cout << "Day of the year cannot be negative\nRe-enter the day of the year: ";
    }

    DayOfYear day(tempNum);

    cout << day.print();

    return 0;
}
