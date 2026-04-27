#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long sapXepChuSo(int n)
{
    vector<int> chuSo;
    int temp = n;
    while (temp > 0)
    {
        chuSo.push_back(temp % 10);
        temp /= 10;
    }
    sort(chuSo.begin(), chuSo.end());

    long long ketQua = 0;
    for (int d : chuSo)
        ketQua = ketQua * 10 + d;
    return ketQua;
}

void hienThiChuSo(int n, const string &nhan)
{
    vector<int> chuSo;
    int temp = n;
    while (temp > 0)
    {
        chuSo.push_back(temp % 10);
        temp /= 10;
    }
    reverse(chuSo.begin(), chuSo.end());
    cout << nhan << ": ";
    for (int d : chuSo)
        cout << d << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int N;
    do
    {
        cout << "Nhap so nguyen duong N (1 den 999999): ";
        cin >> N;
        if (N <= 0 || N > 999999)
            cout << "So phai trong khoang [1, 999999]. Nhap lai.\n";
    } while (N <= 0 || N > 999999);

    hienThiChuSo(N, "Cac chu so ban dau");

    long long ketQua = sapXepChuSo(N);

    vector<int> chuSo;
    int temp = N;
    while (temp > 0)
    {
        chuSo.push_back(temp % 10);
        temp /= 10;
    }
    sort(chuSo.begin(), chuSo.end());
    cout << "Cac chu so tang dan: ";
    for (int d : chuSo)
        cout << d << " ";
    cout << endl;

    cout << "So sau khi sap xep: " << ketQua << endl;

    return 0;
}
