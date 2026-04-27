#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    double chieuCaoDung = 0, chieuCaoTri = 0;

    cout << "Nhap chieu cao cua Dung (cm): ";
    cin >> chieuCaoDung;
    cout << "Nhap chieu cao cua Tri (cm): ";
    cin >> chieuCaoTri;

    cout << fixed << setprecision(1);
    if (chieuCaoDung == chieuCaoTri)
    {
        cout << "\nDung va Tri co chieu cao bang nhau (" << chieuCaoDung << " cm)." << endl;
    }
    else if (chieuCaoDung > chieuCaoTri)
    {
        cout << "\nDung cao hon Tri "
             << (chieuCaoDung - chieuCaoTri) << " cm." << endl;
    }
    else
    {
        cout << "\nTri cao hon Dung "
             << (chieuCaoTri - chieuCaoDung) << " cm." << endl;
    }

    return 0;
}
