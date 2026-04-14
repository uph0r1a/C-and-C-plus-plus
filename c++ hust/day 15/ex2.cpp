#include <iostream>
#include <string>
using namespace std;

class Time
{
protected:
    int hour, min, sec;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        min = m;
        sec = s;
    }

    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getSec() const { return sec; }
};

class MilTime : public Time
{
private:
    int milHours, milSeconds;

public:
    class BadHour
    {
    };
    class BadSeconds
    {
    };

    MilTime(int mHours, int mSeconds)
    {
        setTime(mHours, mSeconds);
    }

    void setTime(int mHours, int mSeconds)
    {
        if (mHours < 0 || mHours > 2359)
            throw BadHour();

        if (mSeconds < 0 || mSeconds > 59)
            throw BadSeconds();

        milHours = mHours;
        milSeconds = mSeconds;

        hour = milHours / 100;
        min = milHours % 100;
        sec = milSeconds;
    }

    int getHour() const
    {
        return milHours;
    }

    string getStandHr() const
    {
        int h = hour;
        string period = (h >= 12) ? "PM" : "AM";

        if (h == 0)
            h = 12;
        else if (h > 12)
            h -= 12;

        return to_string(h) + ":" + to_string(min) + " " + period;
    }
};