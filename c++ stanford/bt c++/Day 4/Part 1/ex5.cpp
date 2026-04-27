#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class ChuyenDoi
{
private:
    const string donVi[10] = {
        "khong", "mot", "hai", "ba", "bon",
        "nam", "sau", "bay", "tam", "chin"};
    long long m_value;

    string docNhom(int n, bool coTram) const
    {
        if (n == 0)
            return "";

        string result;
        int tram = n / 100;
        int chuc = (n % 100) / 10;
        int dv = n % 10;

        if (tram > 0)
        {
            result += donVi[tram] + " tram";
        }
        else if (coTram)
        {
            result += "khong tram";
        }

        if (chuc == 0)
        {
            if (dv > 0)
            {
                if (tram > 0 || coTram)
                    result += " linh";
                result += " " + donVi[dv];
            }
        }
        else if (chuc == 1)
        {
            result += " muoi";
            if (dv == 1)
                result += " mot";
            else if (dv == 5)
                result += " lam";
            else if (dv > 0)
                result += " " + donVi[dv];
        }
        else
        {
            result += " " + donVi[chuc] + " muoi";
            if (dv == 1)
                result += " mot";
            else if (dv == 5)
                result += " lam";
            else if (dv > 0)
                result += " " + donVi[dv];
        }

        return result;
    }

    static string trim(const string &s)
    {
        size_t a = s.find_first_not_of(' ');
        if (a == string::npos)
            return "";
        size_t b = s.find_last_not_of(' ');
        return s.substr(a, b - a + 1);
    }

public:
    ChuyenDoi()
        : m_value(0) {}
    explicit ChuyenDoi(long long n)
    {
        setValue(n);
    }

    void setValue(long long n)
    {
        if (n < 0 || n > 1'000'000'000LL)
            throw out_of_range("So phai nam trong [0, 1,000,000,000]");
        m_value = n;
    }

    long long getValue() const
    {
        return m_value;
    }

    string docSo() const
    {
        if (m_value == 0)
            return "Khong";
        if (m_value == 1'000'000'000LL)
            return "Mot ty";

        long long v = m_value;
        int trieu = (int)((v / 1'000'000LL) % 1000);
        int nghin = (int)((v / 1'000LL) % 1000);
        int dv = (int)(v % 1000);

        string result;

        if (trieu > 0)
        {
            result += trim(docNhom(trieu, false)) + " trieu";
        }
        if (nghin > 0)
        {
            if (!result.empty())
                result += ", ";
            result += trim(docNhom(nghin, trieu > 0)) + " nghin";
        }
        if (dv > 0)
        {
            if (!result.empty())
                result += ", ";
            result += trim(docNhom(dv, nghin > 0 || trieu > 0));
        }

        if (!result.empty())
            result[0] = toupper(result[0]);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    long long tests[] = {
        0, 1, 5, 10, 11, 15, 20, 21, 100, 101, 110, 115,
        1000, 1001, 1010, 1100, 10000, 100000,
        1094507, 1000000, 999999999, 1000000000};

    for (long long n : tests)
    {
        ChuyenDoi cd(n);
        cout << n << " -> " << cd.docSo() << "\n";
    }

    cout << "\n--- Nhap so de doc ---\n";
    long long n;
    while (true)
    {
        cout << "Nhap so (0 - 1,000,000,000): ";
        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        try
        {
            ChuyenDoi cd(n);
            cout << "=> " << cd.docSo() << "\n\n";
        }
        catch (const out_of_range &e)
        {
            cout << "Loi: " << e.what() << "\n";
        }
    }
}