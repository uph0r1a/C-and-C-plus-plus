#include <iostream>
#include <string>
using namespace std;

class Time
{
protected:
    int hour;
    int min;
    int sec;

public:
    Time()
    {
        hour = 0;
        min = 0;
        sec = 0;
    }

    Time(int h, int m, int s)
    {
        hour = h;
        min = m;
        sec = s;
    }

    int getHour() const
    {
        return hour;
    }

    int getMin() const
    {
        return min;
    }

    int getSec() const
    {
        return sec;
    }
};

class MilTime : public Time
{
private:
    int milHours, milSeconds;

public:
    MilTime(int mHours, int mSecond)
        : Time(mHours / 100, mHours % 100, mSecond)
    {
        milHours = mHours;
        milSeconds = mSecond;

        if (!(milHours <= 2359 && milHours >= 0 && milSeconds <= 59 && milSeconds >= 0))
        {
            cout << "Invalid input";
            exit(0);
        }
    }

    void setTime(int mHours, int mSecond)
    {
        milHours = mHours;
        milSeconds = mSecond;

        if (milHours <= 2359 && milHours >= 0 && milSeconds <= 59 && milSeconds >= 0)
        {
            Time(milHours / 100, milHours % 100, milSeconds);
        }
        else
        {
            cout << "Invalid input";
            exit(0);
        }
    }

    int getHour() const
    {
        return milHours;
    }

    string getStandHr() const
    {
        int h = Time::getHour();
        string period = (h >= 12) ? "pm" : "am";

        if (h == 0)
            h = 12;
        else if (h > 12)
            h -= 12;

        return to_string(h) + ":" + to_string(getMin()) + " " + period;
    }
};

int main(int argc, char const *argv[])
{
    int mHour, mSecond;

    cout << "Enter military hour: ";
    cin >> mHour;

    cout << "Enter military second: ";
    cin >> mSecond;

    MilTime miltime(mHour, mSecond);

    cout << miltime.getHour() << endl;
    cout << miltime.getStandHr() << endl;

    return 0;
}
