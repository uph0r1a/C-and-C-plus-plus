#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void inputValidate(string &name)
{
    while (1)
    {
        getline(cin, name);
        if (!name.empty())
        {
            break;
        }
        cout << "Payee's name cannot be empty\nRe-enter payee's name: ";
    }
}

void inputValidate(float &amount)
{
    while (1)
    {
        cin >> amount;
        if (amount >= 0 && amount <= 10000)
        {
            break;
        }
        cout << "Amount of the check must be between $0 and $10000\nRe-enter amount of the check: ";
    }
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(int day, int month, int year)
{
    if (month < 1 || month > 12)
    {
        return false;
    }

    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (day < 1 || day > daysInMonth[month - 1])
    {
        return false;
    }

    return true;
}

void inputValidate(int &day, int &month, int &year)
{
    while (1)
    {
        cin >> day;
        cin >> month;
        cin >> year;
        if (isValidDate(day, month, year))
        {
            break;
        }
        cout << "Invalid date\nRe-enter the day,month and year(Press Enter after each one): ";
    }
}

string convertToWords(int n)
{
    string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string result = "";

    if (n >= 1000)
    {
        result += ones[n / 1000] + " thousand ";
        n %= 1000;
    }

    if (n >= 100)
    {
        result += ones[n / 100] + " hundred ";
        n %= 100;
    }

    if (n >= 20)
    {
        result += tens[n / 10] + " ";
        n %= 10;
    }

    if (n >= 10)
    {
        result += teens[n - 10];
        return result;
    }

    if (n > 0)
    {
        result += ones[n];
    }

    return result;
}

string convertCentsToWords(int cents)
{
    string ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    string result = "";

    if (cents >= 10)
    {
        result += tens[cents / 10] + " ";
        cents %= 10;
    }

    if (cents > 0)
    {
        result += ones[cents];
    }

    if (result == "")
    {
        return "zero cents";
    }

    return result + " cents";
}

int main(int argc, char const *argv[])
{
    int day, month, year;
    float amount;
    string name;

    cout << "Enter the payee's name: ";
    inputValidate(name);

    cout << "Enter the amount of the check: ";
    inputValidate(amount);

    cout << "Enter the day,month and year(Press Enter after each one): ";
    inputValidate(day, month, year);

    int dollars = static_cast<int>(amount);
    int cents = static_cast<int>((amount - dollars) * 100);

    string dollarWords = convertToWords(dollars);
    string centWords = convertCentsToWords(cents);

    system("clear");
    cout << setw(50) << "Date: " << month << "/" << day << "/" << year << endl
         << endl
         << "Pay to the Order of: " << name << setw(11) << "$" << amount << endl
         << endl
         << dollarWords << "and " << centWords << endl;

    return 0;
}
