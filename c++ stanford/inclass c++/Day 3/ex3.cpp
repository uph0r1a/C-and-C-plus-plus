#include <iostream>
using namespace std;

bool laNamNhuan(int nam)
{
    return (nam % 4 == 0 && nam % 100 != 0) ||
           (nam % 400 == 0);
}

void timNamNhuan(int tuNam, int denNam)
{
    cout << "Cac nam nhuan tu " << tuNam << " den " << denNam << ":\n";
    bool coNamNhuan = false;
    for (int i = tuNam; i <= denNam; i++)
    {
        if (laNamNhuan(i))
        {
            cout << "  " << i << "\n";
            coNamNhuan = true;
        }
    }
    if (!coNamNhuan)
        cout << "(Khong co nam nhuan trong khoang nay)\n";
}

int main(int argc, char const *argv[])
{
    int tuNam = 0, denNam = 0;

    cout << "Nhap tu nam : ";
    cin >> tuNam;
    cout << "Nhap den nam: ";
    cin >> denNam;

    if (tuNam > denNam)
    {
        cout << "Tu nam phai nho hon den nam!\n";
        return 1;
    }

    timNamNhuan(tuNam, denNam);

    return 0;
}
