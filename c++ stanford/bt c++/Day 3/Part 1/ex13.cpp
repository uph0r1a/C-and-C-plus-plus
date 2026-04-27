#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class ChuyenDoi
{
public:
    static long long nhiPhanSangThapPhan(const string &nhiPhan, bool inBuoc = false)
    {
        if (nhiPhan.empty())
            throw invalid_argument("Chuoi nhi phan khong duoc de trong.");

        string chuoi = nhiPhan;
        bool amSo = false;
        if (chuoi[0] == '-')
        {
            amSo = true;
            chuoi = chuoi.substr(1);
        }
        if (chuoi.find_first_not_of("01") != string::npos)
            throw invalid_argument("Chi chap nhan cac ky tu '0' va '1'.");

        long long ketQua = 0;
        int luy = 0;
        vector<pair<char, long long>> buoc;

        for (int i = (int)chuoi.size() - 1; i >= 0; i--)
        {
            int bit = chuoi[i] - '0';
            long long giaTri = (long long)bit << luy;
            buoc.push_back({chuoi[i], giaTri});
            ketQua += giaTri;
            luy++;
        }

        if (inBuoc)
        {
            cout << "\nCac buoc tinh:" << endl;
            for (int i = (int)buoc.size() - 1; i >= 0; i--)
            {
                int viTri = (int)buoc.size() - 1 - i;
                cout << "  Vi tri " << viTri << ": bit=" << buoc[i].first
                     << "  gia tri = " << buoc[i].first << " x 2^" << viTri
                     << " = " << buoc[i].second << endl;
            }
            cout << "Tong = " << ketQua << endl;
        }

        return amSo ? -ketQua : ketQua;
    }
};

int main(int argc, char const *argv[])
{
    cout << "=== CHUYEN NHI PHAN -> THAP PHAN ===" << endl;

    int lua;
    do
    {
        cout << "\n1. Chuyen doi | 0. Thoat -> Chon: ";
        cin >> lua;

        if (lua == 1)
        {
            string nhiPhan;
            cout << "Nhap so nhi phan: ";
            cin >> nhiPhan;

            try
            {
                long long kq = ChuyenDoi::nhiPhanSangThapPhan(nhiPhan, true);
                cout << "\nKet qua: " << nhiPhan << " (nhi phan) = " << kq << " (thap phan)" << endl;
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
