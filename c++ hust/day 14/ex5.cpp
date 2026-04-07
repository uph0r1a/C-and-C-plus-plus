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
    MilTime(int mHours = 0, int mSecond = 0)
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

class TimeClock : public MilTime
{
private:
    MilTime start;
    MilTime end;

    int toSeconds(const MilTime &t) const
    {
        int h = t.Time::getHour();
        int m = t.getMin();
        int s = t.getSec();
        return h * 3600 + m * 60 + s;
    }

public:
    TimeClock(int s = 0, int e = 0)
        : start(s, 0), end(e, 0) {}

    string getTimeElapsed() const
    {
        int startSec = toSeconds(start);
        int endSec = toSeconds(end);

        int diff = endSec - startSec;

        int hours = diff / 3600;
        int minutes = (diff % 3600) / 60;

        return to_string(hours) + " hours " + to_string(minutes) + " minutes";
    }
};

int main(int argc, char const *argv[])
{
    int start, end;

    cout << "Enter start time: ";
    cin >> start;

    cout << "Enter end time: ";
    cin >> end;

    TimeClock elapsed(start, end);

    cout << elapsed.getTimeElapsed();

    return 0;
}