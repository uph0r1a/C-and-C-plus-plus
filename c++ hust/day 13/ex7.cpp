#include <iostream>
#include <string>
using namespace std;

class Month
{
private:
    string name;
    int monthNumber;

public:
    inline static string monthStr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    Month()
    {
        monthNumber = 1;
        name = "January";
    }

    Month(string monthName)
        : name(monthName)
    {
        for (int i = 0; i < 12; i++)
        {
            if (name == monthStr[i])
            {
                name = monthName;
                monthNumber = i + 1;
                return;
            }
        }
        monthNumber = 1;
        name = "January";
    }

    Month(int monthNum)
    {
        if (monthNum >= 1 && monthNum <= 12)
        {
            monthNumber = monthNum;
            name = monthStr[monthNumber - 1];
        }
        else
        {
            monthNumber = 1;
            name = "January";
        }
    }

    void setName(string monthName)
    {
        name = monthName;
    }

    void setNum(int monthNum)
    {
        monthNumber = monthNum;
    }

    string getName() const
    {
        return name;
    }

    int getNum() const
    {
        return monthNumber;
    }

    Month &operator++()
    {
        ++monthNumber;

        if (monthNumber > 12)
        {
            monthNumber = 1;
        }

        name = monthStr[monthNumber - 1];
        return *this;
    }

    Month operator++(int)
    {
        Month temp = *this;

        monthNumber++;

        if (monthNumber > 12)
        {
            monthNumber = 1;
        }

        name = monthStr[monthNumber - 1];
        return temp;
    }

    Month &operator--()
    {
        --monthNumber;

        if (monthNumber < 1)
        {
            monthNumber = 12;
        }

        name = monthStr[monthNumber - 1];
        return *this;
    }

    Month operator--(int)
    {
        Month temp = *this;

        monthNumber--;
        if (monthNumber < 1)
        {
            monthNumber = 12;
        }
        name = monthStr[monthNumber - 1];
        return temp;
    }

    friend ostream &operator<<(ostream &out, const Month &obj)
    {
        out << obj.name << " " << obj.monthNumber;
        return out;
    }

    friend istream &operator>>(istream &in, Month &obj)
    {
        cout << "Enter month number: ";
        while (1)
        {
            in >> obj.monthNumber;

            if (obj.monthNumber >= 1 && obj.monthNumber <= 12)
            {
                break;
            }
            cout << "Month number must be between 1 and 12\nRe-enter month number: ";
        }

        obj.name = Month::monthStr[obj.monthNumber - 1];
        return in;
    }
};

int main(int argc, char const *argv[])
{
    Month m1;
    Month m2("March");
    Month m3(10);

    cout << "Initial Months:\n";
    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl;
    cout << "m3: " << m3 << endl;

    cout << "\nAfter prefix ++ on m1:\n";
    ++m1;
    cout << "m1: " << m1 << endl;

    cout << "\nAfter postfix ++ on m2:\n";
    m2++;
    cout << "m2: " << m2 << endl;

    cout << "\nAfter prefix -- on m3:\n";
    --m3;
    cout << "m3: " << m3 << endl;

    cout << "\nAfter postfix -- on m1:\n";
    m1--;
    cout << "m1: " << m1 << endl;

    Month m4;
    cin >> m4;
    cout << "You entered: " << m4 << endl;

    return 0;
}
