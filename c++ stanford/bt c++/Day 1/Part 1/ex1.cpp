#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int tuoi;
    cout << "Nhap tuoi: ";
    cin >> tuoi;

    long long soCay;
    cout << "Nhap so luong cay trong thanh pho: ";
    cin >> soCay;

    double doDaiCanh;
    cout << "Nhap do dai canh tam giac: ";
    cin >> doDaiCanh;

    double khoangCach;
    cout << "Nhap khoang cach giua cac hanh tinh (km): ";
    cin >> khoangCach;

    int chuSo;
    do
    {
        cout << "Nhap mot chu so (0-9): ";
        cin >> chuSo;
    } while (chuSo < 0 || chuSo > 9);

    double A, B;
    cout << "Nhap he so A: ";
    cin >> A;
    cout << "Nhap he so B: ";
    cin >> B;
    if (A != 0)
        cout << "Nghiem x = " << -B / A << "\n";
    else
        cout << "Phuong trinh vo nghiem (A = 0)\n";

    char chuCai;
    cout << "Nhap mot chu cai: ";
    cin >> chuCai;

    double a, b, c;
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;
    double delta = b * b - 4 * a * c;
    cout << "Biet thuc Delta = " << delta << "\n";

    return 0;
}
