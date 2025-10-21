#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    const float YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
    float dollar;
    cout << "Enter the amount in dollar: ";
    cin >> dollar;
    cout << "Japanese yen: " << dollar * YEN_PER_DOLLAR << "\n"
         << "Euros: " << dollar * EUROS_PER_DOLLAR << endl;
    return 0;
}
