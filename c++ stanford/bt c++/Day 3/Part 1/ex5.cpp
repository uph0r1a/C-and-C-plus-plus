#include <iostream>
using namespace std;

bool laNamNhuan(int nam)
{
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

void inNamNhuan(int tuNam, int denNam)
{
    cout << "Cac nam nhuan tu " << tuNam << " den " << denNam << ":" << endl;

    int count = 0;
    for (int nam = tuNam; nam <= denNam; nam++)
    {
        if (laNamNhuan(nam))
        {
            cout << nam;
            count++;
            if (count % 10 == 0)
                cout << endl;
            else
                cout << "  ";
        }
    }

    cout << endl;
    cout << "Tong so nam nhuan: " << count << " nam" << endl;
}

int main(int argc, char const *argv[])
{
    int nam;
    cout << "Nhap mot nam de kiem tra: ";
    cin >> nam;
    cout << nam << (laNamNhuan(nam) ? " la nam nhuan." : " khong phai nam nhuan.") << endl;
    cout << endl;

    inNamNhuan(1000, 2000);

    return 0;
}
