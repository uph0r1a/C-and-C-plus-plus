#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float number_of_gallon = 20, average_mpg_town = 23.5, average_mpg_highway = 28.9, distance_town = number_of_gallon * average_mpg_town, distance_highway = number_of_gallon * average_mpg_highway;
    cout << "In town " << distance_town << " miles" << "\n"
         << "In highway " << distance_highway << " miles" << endl;
    return 0;
}
