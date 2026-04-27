#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

class Point
{
private:
    string name;
    double x;
    double y;

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
            cout << "[!] Gia tri khong hop le, vui long nhap lai.\n";
        }
    }

    static string readString(const string &prompt)
    {
        string s;
        while (true)
        {
            cout << prompt;
            cin >> s;
            if (!s.empty())
                return s;
            cout << "[!] Ten diem khong duoc de trong.\n";
        }
    }

public:
    Point()
        : name("A"),
          x(0.0),
          y(0.0) {}

    Point(double x, double y)
        : name("O"),
          x(x),
          y(y) {}

    Point(const string &name, double x, double y)
        : name(name),
          x(x),
          y(y) {}

    Point(const Point &other)
        : name(other.name),
          x(other.x),
          y(other.y) {}

    string getName() const
    {
        return name;
    }

    double getX() const
    {
        return x;
    }

    double getY() const
    {
        return y;
    }

    void setName(const string &n)
    {
        if (n.empty())
            throw invalid_argument("Ten diem khong duoc rong");
        name = n;
    }

    void setX(double val)
    {
        x = val;
    }

    void setY(double val)
    {
        y = val;
    }

    void nhap()
    {
        name = readString("Ten diem: ");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        x = readDouble("Hoanh do (x): ");
        y = readDouble("Tung do (y): ");
    }

    void inRa() const
    {
        cout << name << "("
             << fixed << setprecision(2) << x << ", "
             << fixed << setprecision(2) << y << ")\n";
    }

    double khoangCach(const Point &other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool bangNhau(const Point &other) const
    {
        return x == other.x && y == other.y;
    }

    friend ostream &operator<<(ostream &os, const Point &p)
    {
        os << p.name << "("
           << fixed << setprecision(2) << p.x << ", "
           << fixed << setprecision(2) << p.y << ")";
        return os;
    }
};

int main(int argc, char const *argv[])
{
    cout << "=== Test cac constructor ===\n\n";

    Point p1;
    cout << "2i) Mac dinh: ";
    p1.inRa();

    Point p2(3.0, 4.0);
    cout << "2ii) Hai so thuc: ";
    p2.inRa();

    Point p3("B", 1.5, -2.5);
    cout << "2iii) Chuoi + 2 STs: ";
    p3.inRa();

    Point p4(p3);
    cout << "2iv) Sao chep p3: ";
    p4.inRa();

    cout << "\n=== Test get/set ===\n";
    p1.setName("C");
    p1.setX(7.0);
    p1.setY(-3.0);
    cout << "Sau khi set: ";
    p1.inRa();
    cout << "getName=" << p1.getName()
         << "getX=" << p1.getX()
         << "getY=" << p1.getY() << "\n";

    cout << "\n=== Khoang cach ===\n";
    cout << "d(" << p2 << ", O(0,0)) = "
         << fixed << setprecision(4) << p2.khoangCach(Point()) << "\n";

    cout << "\n=== Nhap diem moi ===\n";
    Point p5;
    p5.nhap();
    cout << "Diem vua nhap: ";
    p5.inRa();

    return 0;
}