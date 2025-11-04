#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float number_of_calories, fat_grams;
loop3:
loop1:
    cout << "Enter the number of calories: ";
    cin >> number_of_calories;
    if (number_of_calories < 0)
    {
        cout << "The number of calories are not less than 0\n";
        goto loop1;
    }

loop2:
    cout << "Enter the fat grams: ";
    cin >> fat_grams;
    if (fat_grams < 0)
    {
        cout << "The fat grams are not less than 0\n";
        goto loop2;
    }

    if ((fat_grams * 9) > number_of_calories)
    {
        cout << "Either the calories or fat grams were incorrectly entered\n";
        goto loop3;
    }

    if (((fat_grams * 9) / number_of_calories) < 0.3)
    {
        cout << "The food is low in fat";
    }
    return 0;
}
