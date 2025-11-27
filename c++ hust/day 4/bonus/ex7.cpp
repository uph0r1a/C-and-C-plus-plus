#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream f("number.txt");
    int number, sum = 0;

    while (f >> number)
    {
        sum += number;
    }
    cout << "Sum: " << sum;
    return 0;
}