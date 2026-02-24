#include <iostream>
#include <string>
using namespace std;

class Numbers
{
private:
    string lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string lessThan100[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    string thousand = "thousand";
    int number;

public:
    Numbers(int num)
    {
        number = num;
    }

    string print() const
    {
        string translated = "";

        int temp = number;

        if (number == 0)
            return "zero";

        int thousands = temp / 1000;
        temp %= 1000;

        int hundreds = temp / 100;
        temp %= 100;

        if (thousands > 0)
        {
            translated += lessThan20[thousands] + " " + thousand + " ";
        }

        if (hundreds > 0)
        {
            translated += lessThan20[hundreds] + " " + hundred + " ";
        }

        if (temp >= 20)
        {
            int tenths = temp / 10;
            int ones = temp % 10;

            translated += lessThan100[tenths - 2] + " ";

            if (ones > 0)
            {
                translated += lessThan20[ones];
            }
        }
        else if (temp > 0)
        {
            translated += lessThan20[temp];
        }

        return translated;
    }
};

int main(int argc, char const *argv[])
{
    int tempNum;
    cout << "Enter the number between 0 and 9999: ";
    while (1)
    {
        cin >> tempNum;
        if (tempNum >= 0 && tempNum <= 9999)
        {
            break;
        }
        cout << "Number must be between 0 and 9999\nRe-enter the number between 0 and 9999: ";
    }
    Numbers num(tempNum);

    cout << num.print() + "\n";

    return 0;
}
