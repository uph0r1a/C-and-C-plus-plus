#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    int total;
    do
    {
        cout << "Nhap so giay (0 - 68399): ";
        cin >> total;
    } while (total < 0 || total > 68399);

    int gio = total / 3600;
    int phut = (total % 3600) / 60;
    int giay = total % 60;

    cout << setfill('0')
         << setw(2) << gio << ":"
         << setw(2) << phut << ":"
         << setw(2) << giay << "\n";
    return 0;
}
