#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int number_of_male, number_of_female, total;
    float percentage_male, percentage_female;

    cout << "Enter the number of males: ";
    cin >> number_of_male;
    cout << "Enter the number of females: ";
    cin >> number_of_female;

    total = number_of_female + number_of_male;
    percentage_male = number_of_male / (float)total;
    percentage_female = number_of_female / (float)total;

    cout << "Percentage of males: " << percentage_male * 100 << "%" << "\n"
         << "Percentage of females: " << percentage_female * 100 << "%" << endl;
    return 0;
}
