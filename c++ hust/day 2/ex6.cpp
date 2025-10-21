#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float cookies_wanna_make, multiplier;
    cout << "how many cookies do you wants to make: ";
    cin >> cookies_wanna_make;
    multiplier = cookies_wanna_make / 48;
    cout << "Number of cups of sugar needed: " << multiplier * 1.5 << "\n"
         << "Number of cups of butter needed: " << multiplier * 1 << "\n"
         << "Number of cups of flour needed: " << multiplier * 2.75 << "\n";
    return 0;
}
