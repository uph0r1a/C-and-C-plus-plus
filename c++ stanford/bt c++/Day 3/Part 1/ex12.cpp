#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class ChuyenDoi
{
public:
    static string thapPhanSangNhiPhan(long long n)
    {
        if (n < 0)
            throw invalid_argument("Chi ho tro so nguyen khong am.");
        if (n == 0)
            return "0";

        string ketQua = "";
        while (n > 0)
        {
            ketQua = (char)('0' + n % 2) + ketQua;
            n /= 2;
        }
        return ketQua;
    }

    static long long nhiPhanSangThapPhan(const string &nhiPhan)
    {
        if (nhiPhan.empty())
            throw invalid_argument("Chuoi rong.");
        if (nhiPhan.find_first_not_of("01") != string::npos)
            throw invalid_argument("Chuoi nhi phan chi gom ky tu '0' va '1'.");

        long long ketQua = 0;
        for (char bit : nhiPhan)
        {
            ketQua = ketQua * 2 + (bit - '0');
        }
        return ketQua;
    }

    static bool laNhiPhanHopLe(const string &s)
    {
        return !s.empty() && s.find_first_not_of("01") == string::npos;
    }
};

void menu()
{
    cout << "\n========================================" << endl;
    cout << "  CHUYEN DOI SO NHI PHAN <-> THAP PHAN" << endl;
    cout << "========================================" << endl;
    cout << "1. Thap phan -> Nhi phan" << endl;
    cout << "2. Nhi phan -> Thap phan" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon: ";
}

int main(int argc, char const *argv[])
{
    int lua;
    do
    {
        menu();
        cin >> lua;

        if (lua == 1)
        {
            long long so;
            cout << "Nhap so thap phan (>= 0): ";
            cin >> so;
            try
            {
                string kq = ChuyenDoi::thapPhanSangNhiPhan(so);
                cout << so << " (thap phan) = " << kq << " (nhi phan)" << endl;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << endl;
            }
        }
        else if (lua == 2)
        {
            string nhiPhan;
            cout << "Nhap so nhi phan (chi 0 va 1): ";
            cin >> nhiPhan;
            try
            {
                long long kq = ChuyenDoi::nhiPhanSangThapPhan(nhiPhan);
                cout << nhiPhan << " (nhi phan) = " << kq << " (thap phan)" << endl;
            }
            catch (const exception &e)
            {
                cout << "Loi: " << e.what() << endl;
            }
        }
        else if (lua != 0)
        {
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (lua != 0);

    cout << "Tam biet!" << endl;
    return 0;
}
