#include <iostream>
using namespace std;

class NumDays
{
private:
    int hour;

public:
    NumDays(int h = 0)
    {
        hour = h;
    }

    NumDays operator+(NumDays &add) const
    {
        NumDays sum(hour + add.hour);
        return sum;
    }

    NumDays operator-(NumDays &sub) const
    {
        NumDays difference(hour - sub.hour);
        return difference;
    }

    NumDays &operator++()
    {
        ++hour;
        return *this;
    }

    NumDays operator++(int)
    {
        NumDays temp = *this;
        operator++();
        return temp;
    }

    NumDays &operator--()
    {
        --hour;
        return *this;
    }

    NumDays operator--(int)
    {
        NumDays temp = *this;
        operator--();
        return temp;
    }

    float getDay() const
    {
        return hour / 8.0;
    }
};

int main(int argc, char const *argv[])
{
    NumDays hour1(8);
    NumDays hour2(12);
    NumDays hour3 = hour1 + hour2;
    NumDays hour4 = hour2 - hour1;

    cout << hour1.getDay() << endl
         << hour3.getDay() << endl
         << hour4.getDay() << endl
         << (++hour1).getDay() << endl
         << (hour1++).getDay() << endl
         << (--hour3).getDay() << endl
         << (hour3--).getDay() << endl;
    return 0;
}
