#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float item1 = 15.95, item2 = 24.95, item3 = 6.95, item4 = 12.95, item5 = 3.95;
    cout << item1 << "\n"
         << item2 << "\n"
         << item3 << "\n"
         << item4 << "\n"
         << item5 << "\n"
         << item1 + item2 + item3 + item4 + item5 << "\n"
         << (item1 + item2 + item3 + item4 + item5) * 0.07 << "\n"
         << item1 + item2 + item3 + item4 + item5 + (item1 + item2 + item3 + item4 + item5) * 0.07 << endl;
    return 0;
}
