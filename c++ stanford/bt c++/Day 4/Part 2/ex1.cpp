#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <limits>
using namespace std;

class SoPhuc
{
private:
    double re;
    double im;

    static double readDouble(const string &prompt)
    {
        double v;
        while (true)
        {
            cout << prompt;
            if (cin >> v)
                return v;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[!] Gia tri khong hop le, nhap lai.\n";
        }
    }

    static string to_string_prec(double v)
    {
        ostringstream oss;
        oss << fixed << setprecision(4) << v;
        string s = oss.str();
        size_t dot = s.find('.');
        if (dot != string::npos)
        {
            s.erase(s.find_last_not_of('0') + 1);
            if (s.back() == '.')
                s.pop_back();
        }
        return s;
    }

public:
    SoPhuc()
        : re(0.0),
          im(0.0) {}

    SoPhuc(double real, double imag)
        : re(real),
          im(imag) {}

    double getReal() const
    {
        return re;
    }

    double getImag() const
    {
        return im;
    }

    void setReal(double r)
    {
        re = r;
    }

    void setImag(double i)
    {
        im = i;
    }

    void nhap()
    {
        cout << "Nhap so phuc:\n";
        re = readDouble("Phan thuc = ");
        im = readDouble("Phan ao = ");
    }

    void inRa(const string &label = "So phuc") const
    {
        cout << label << ": " << toString() << "\n";
    }

    string toString() const
    {
        string s = to_string_prec(re);
        if (im >= 0 || isnan(im))
            s += " + " + to_string_prec(im) + "i";
        else
            s += " - " + to_string_prec(-im) + "i";
        return s;
    }

    SoPhuc cong(const SoPhuc &other) const
    {
        return SoPhuc(re + other.re, im + other.im);
    }

    SoPhuc tru(const SoPhuc &other) const
    {
        return SoPhuc(re - other.re, im - other.im);
    }

    SoPhuc nhan(const SoPhuc &other) const
    {
        return SoPhuc(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    SoPhuc chia(const SoPhuc &other) const
    {
        double mauSo = other.re * other.re + other.im * other.im;
        if (mauSo == 0.0)
            throw runtime_error("Khong the chia cho so phuc bang 0");
        return SoPhuc((re * other.re + im * other.im) / mauSo, (im * other.re - re * other.im) / mauSo);
    }

    SoPhuc binhPhuong() const
    {
        return SoPhuc(re * re - im * im, 2.0 * re * im);
    }

    double modulus() const
    {
        return sqrt(re * re + im * im);
    }

    SoPhuc operator+(const SoPhuc &o) const
    {
        return cong(o);
    }

    SoPhuc operator-(const SoPhuc &o) const
    {
        return tru(o);
    }

    SoPhuc operator*(const SoPhuc &o) const
    {
        return nhan(o);
    }

    SoPhuc operator/(const SoPhuc &o) const
    {
        return chia(o);
    }

    friend ostream &operator<<(ostream &os, const SoPhuc &z)
    {
        return os << z.toString();
    }
};

static void printSeparator(const string &title)
{
    cout << "\n--- " << title << " ---\n";
}

int main(int argc, char const *argv[])
{
    printSeparator("Constructor mac dinh");
    SoPhuc z0;
    z0.inRa("z0 (mac dinh)");

    printSeparator("Nhap va in");
    SoPhuc z1, z2;
    cout << "Nhap z1:\n";
    z1.nhap();
    cout << "Nhap z2:\n";
    z2.nhap();
    z1.inRa("z1");
    z2.inRa("z2");

    printSeparator("Cong / Tru / Nhan / Chia");
    (z1 + z2).inRa("z1 + z2");
    (z1 - z2).inRa("z1 - z2");
    (z1 * z2).inRa("z1 * z2");
    try
    {
        (z1 / z2).inRa("z1 / z2");
    }
    catch (const runtime_error &e)
    {
        cout << "[Loi] " << e.what() << "\n";
    }

    printSeparator("Binh phuong");
    z1.binhPhuong().inRa("z1^2");
    z2.binhPhuong().inRa("z2^2");

    printSeparator("Bonus: |z|");
    cout << "|z1| = " << z1.modulus() << "\n";
    cout << "|z2| = " << z2.modulus() << "\n";

    return 0;
}