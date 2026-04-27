#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int thang, nam;
    do
    {
        cout << "Nhap thang (1-12): ";
        cin >> thang;
    } while (thang < 1 || thang > 12);

    int soNgay;
    if (thang == 2)
    {
        cout << "Nhap nam (de kiem tra nam nhuan): ";
        cin >> nam;
        bool nhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
        soNgay = nhuan ? 29 : 28;
    }
    else
    {
        int thang31[] = {1, 3, 5, 7, 8, 10, 12};
        soNgay = 30;
        for (int t : thang31)
            if (thang == t)
            {
                soNgay = 31;
                break;
            }
    }

    cout << "Thang " << thang << " co " << soNgay << " ngay.\n";
    return 0;
}
