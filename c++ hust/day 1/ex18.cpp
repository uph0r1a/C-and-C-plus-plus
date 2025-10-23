#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int surveyed = 16500;
    cout << "Number of customers in the survey who purchase one or more energy drinks per week: " << surveyed * 0.15 << "\n"
         << "Number of customers in the survey who prefer citrus-flavored energy drinks: " << surveyed * 0.15 * 0.58 << endl;
    return 0;
}
