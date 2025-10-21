#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    float land_in_feet = 391876, acre_to_feet = 43560, land_in_acre = land_in_feet / acre_to_feet;
    cout << land_in_acre << endl;
    return 0;
}
