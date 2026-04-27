#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    const int BASE_HOURS = 40;
    const double BASE_RATE = 10.0;
    const double WEEKDAY_OT_RATE = 12.0;
    const double WEEKEND_OT_RATE = 18.0;

    double otWeekday, otWeekend;

    do
    {
        cout << "So gio lam them T2-T6 (>= 0): ";
        cin >> otWeekday;
    } while (otWeekday < 0);

    do
    {
        cout << "So gio lam them T7-CN (>= 0): ";
        cin >> otWeekend;
    } while (otWeekend < 0);

    double total = BASE_HOURS * BASE_RATE + otWeekday * WEEKDAY_OT_RATE + otWeekend * WEEKEND_OT_RATE;

    cout << fixed << setprecision(2);
    cout << "\nLuong co ban (40h x " << BASE_RATE << "$): " << BASE_HOURS * BASE_RATE << "$\n";
    cout << "Lam them T2-T6: " << otWeekday * WEEKDAY_OT_RATE << "$\n";
    cout << "Lam them T7-CN: " << otWeekend * WEEKEND_OT_RATE << "$\n";
    cout << "Tong luong nhan duoc: " << total << "$\n";

    return 0;
}
