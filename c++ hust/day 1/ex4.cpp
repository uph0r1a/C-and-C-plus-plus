#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float charge = 88.67, tax = charge * 0.0675, tip = (charge + tax) * 0.2;
    cout << charge << "\n"
         << tax << "\n"
         << tip << "\n"
         << charge + tax + tip << endl;
    return 0;
}
