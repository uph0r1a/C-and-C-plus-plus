#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{

    double cau8a = sqrt(3.0 + sqrt(3.0 + sqrt(3.0)));
    double cau8b = 1.0 / (2.0 + 1.0 / (2.0 + 1.0 / 2.0));

    cout << fixed << setprecision(2);
    cout << "a) sqrt(3 + sqrt(3 + sqrt(3))) = " << cau8a << endl;
    cout << "b) 1/(2+1/(2+1/2)) = " << cau8b << endl;

    return 0;
}
