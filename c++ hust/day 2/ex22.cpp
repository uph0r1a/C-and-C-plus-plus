#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    float angle;
    cout << "Enter an angle: ";
    cin >> angle;

    cout << "Sine: " << fixed << setprecision(4) << sin(angle) << "\n"
         << "Cosine: " << fixed << setprecision(4) << cos(angle) << "\n"
         << "Tangent: " << fixed << setprecision(4) << tan(angle) << endl;
    return 0;
}
