#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string number;
    int sum = 0;
    cout << "Enter a string number: ";
    cin >> number;

    for (char c : number)
    {
        sum += static_cast<int>(c) - 48;
    }

    cout << "Sum of digits: " << sum << endl;
    return 0;
}
