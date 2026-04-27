#include <iostream>
#include <string>
using namespace std;

const string DON_VI[] = {"", "một", "hai", "ba", "bốn", "năm", "sáu", "bảy", "tám", "chín"};
const string CHUC[] = {"", "mười", "hai mươi", "ba mươi", "bốn mươi",
                       "năm mươi", "sáu mươi", "bảy mươi", "tám mươi", "chín mươi"};

string docBaChuSo(int num, bool isFirst)
{
    if (num == 0)
        return "";

    string res = "";
    int tram = num / 100;
    int chuc = (num / 10) % 10;
    int donVi = num % 10;

    if (tram > 0)
    {
        res += DON_VI[tram] + " trăm";
        if (chuc == 0 && donVi != 0)
            res += " linh";
    }
    else if (!isFirst && (chuc > 0 || donVi > 0))
    {
        res += "không trăm";
        if (chuc == 0)
            res += " linh";
    }

    if (chuc > 1)
    {
        res += (res.empty() ? "" : " ") + CHUC[chuc];
        if (donVi == 1)
            res += " mốt";
        else if (donVi == 5)
            res += " lăm";
        else if (donVi > 0)
            res += " " + DON_VI[donVi];
    }
    else if (chuc == 1)
    {
        res += (res.empty() ? "mười" : " mười");
        if (donVi > 0)
            res += " " + DON_VI[donVi];
    }
    else if (donVi > 0)
    {
        res += (res.empty() ? "" : " ") + DON_VI[donVi];
    }

    return res;
}

string docSo(long long num)
{
    if (num == 0)
        return "không";
    if (num < 0)
        return "âm " + docSo(-num);

    string res = "";
    long long ty = num / 1000000000LL;
    long long trieu = (num / 1000000) % 1000;
    long long nghin = (num / 1000) % 1000;
    long long donVi = num % 1000;

    if (ty > 0)
    {
        res += docBaChuSo((int)ty, true) + " tỷ";
    }
    if (trieu > 0)
    {
        res += (res.empty() ? "" : " ") + docBaChuSo((int)trieu, res.empty()) + " triệu";
    }
    if (nghin > 0)
    {
        res += (res.empty() ? "" : " ") + docBaChuSo((int)nghin, res.empty()) + " nghìn";
    }
    if (donVi > 0)
    {
        res += (res.empty() ? "" : " ") + docBaChuSo((int)donVi, res.empty());
    }

    return res;
}

int main(int argc, char const *argv[])
{
    long long num;
    do
    {
        cout << "Nhap so nguyen (0 - 1,000,000,000): ";
        cin >> num;
        if (num < 0 || num > 1000000000LL)
            cout << "So nhap khong hop le! Vui long nhap lai." << endl;
    } while (num < 0 || num > 1000000000LL);

    cout << "\nSo: " << num << endl;
    cout << "Doc la: " << docSo(num) << endl;

    long long viDu[] = {0, 5, 15, 100, 1000, 10500, 1094507, 1000000000LL};
    for (long long v : viDu)
    {
        cout << v << " => " << docSo(v) << endl;
    }

    return 0;
}
