#include <iostream>
#include <cmath>
#include <limits>
#include <climits>
using namespace std;

class Calculate
{
public:
    int gcd(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    long long lcm(int a, int b)
    {
        return (long long)abs(a) / gcd(a, b) * abs(b);
    }

    void quadratic(double a, double b, double c)
    {
        if (a == 0)
        {
            if (b == 0)
                cout << (c == 0 ? "Infinite solutions\n" : "No solution\n");
            else
                cout << "Linear solution: x = " << -c / b << "\n";
            return;
        }

        double delta = b * b - 4 * a * c;
        cout << "Delta = " << delta << "\n";

        if (delta > 0)
        {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Two distinct roots:\n"
                 << "x1 = " << x1 << "\n"
                 << "x2 = " << x2 << "\n";
        }
        else if (delta == 0)
        {
            cout << "Double root:\n"
                 << "x  = " << -b / (2 * a) << "\n";
        }
        else
        {
            double re = -b / (2 * a);
            double im = sqrt(-delta) / (2 * a);
            cout << "Complex roots:\n"
                 << "x1 = " << re << " + " << im << "i\n"
                 << "x2 = " << re << " - " << im << "i\n";
        }
    }
};

static int readInt(const string &prompt, int lo, int hi)
{
    int v;
    while (true)
    {
        cout << prompt;
        if (cin >> v && v >= lo && v <= hi)
            return v;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[!] Please enter a value in [" << lo << ", " << hi << "]: ";
    }
}

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
        cout << "[!] Invalid input. Try again: ";
    }
}

int main(int argc, char const *argv[])
{
    Calculate cal;

    cout << "=== Calculator ===\n"
         << "1) GCD & LCM\n"
         << "2) Quadratic equation\n";
    int choice = readInt("Choose (1-2): ", 1, 2);

    if (choice == 1)
    {
        int a = readInt("Enter a (positive): ", 1, INT_MAX);
        int b = readInt("Enter b (positive): ", 1, INT_MAX);
        cout << "GCD(" << a << ", " << b << ") = " << cal.gcd(a, b) << "\n";
        cout << "LCM(" << a << ", " << b << ") = " << cal.lcm(a, b) << "\n";
    }
    else
    {
        double a = readDouble("Enter a: ");
        double b = readDouble("Enter b: ");
        double c = readDouble("Enter c: ");
        cal.quadratic(a, b, c);
    }

    return 0;
}