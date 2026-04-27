#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

bool isValidDate(int m, int d, int y)
{
    if (m < 1 || m > 12 || d < 1 || y < 0)
        return false;
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool nhuan = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (nhuan)
        days[2] = 29;
    return d <= days[m];
}

int main(int argc, char const *argv[])
{
    string input;
    int mm, dd, yy;

    while (true)
    {
        cout << "Nhap ngay dang MM/DD/YY: ";
        getline(cin, input);
        if (sscanf(input.c_str(), "%d/%d/%d", &mm, &dd, &yy) == 3 && isValidDate(mm, dd, yy))
            break;
        cout << "[!] Ngay khong hop le. Nhap lai.\n";
    }

    cout << "Dang VN (DD/MM/YY): "
         << setfill('0') << setw(2) << dd << "/"
         << setw(2) << mm << "/"
         << setw(2) << yy << "\n";
    return 0;
}